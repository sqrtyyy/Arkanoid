//
// Created by aleksei on 06.04.2020.
//

#include "Game.h"
#include "../GameObjects/Blocks/Speed_Block.h"
#include <windows.h>

using std::make_shared;
using std::to_string;

Game::Game(const string& background_texture_source) {
    load_background(background_texture_source);
}
/*
 * \brief Creating the blocks
 */
void Game::init_blocks() {
    srand(time(nullptr));
    vector<shared_ptr<Block>> blocks(BLOCKS_AMOUNT);
    for(int i = 0; i < LINES_AMOUNT; i++){
        for(int j = 0; j < BLOCKS_AMOUNT/LINES_AMOUNT; j++){
            game_field.blocks_num++;
            int block_idx = i * BLOCKS_AMOUNT/LINES_AMOUNT + j;
            int type = rand() % 100;
            type = type < 70 ? 0 : type < 80 ? 1 : type < 95 ? 2 : 3;
            switch (type)
            {
                case 0:
                    blocks[block_idx] = make_shared<Ordinary_Block>();
                    break;
                case 1:
                    blocks[block_idx] = make_shared<Unbreakable_Block>();
                    game_field.blocks_num--;
                    break;
                case 2:
                    blocks[block_idx] = make_shared<Bonus_Block>();
                    break;
                case 3:
                    blocks[block_idx] = make_shared<Speed_Block>();
                default:
                    break;
            }
            blocks[block_idx]->set_position(j * BLOCK_WIDTH + j + BLOCK_WIDTH, i * BLOCK_HEIGHT + BLOCK_HEIGHT + i);
        }
    }
    game_field.blocks = blocks;

}

void Game::Init() {
    score_text.setFont(fonts[0]);
    score_text.setCharacterSize(24);
    score_text.setPosition(1,5);
    FloatRect window_size = background.getLocalBounds();
    init_blocks();
    IntRect platform_size = {0,0,static_cast<int>(window_size.width / 5), static_cast<int>(window_size.height / 20)};
    game_field.platform.change_size(platform_size);
    IntRect bottom_size = {0,0,static_cast<int>(window_size.width), static_cast<int>(window_size.height / 50)};
    game_field.bottom.change_size(bottom_size);
    game_field.platform.set_position(window_size.width / 2 - window_size.width / 10, window_size.height - window_size.height / 10);
    game_field.bottom.set_position(0,window_size.height -game_field.bottom.get_dimensions().height);
    game_field.balls.push_back(make_shared<Ball>());
    float pos_x = game_field.platform.get_position().x + game_field.platform.get_dimensions().width / 2 - game_field.balls.back()->get_dimensions().width / 2;
    float pos_y = game_field.platform.get_position().y - game_field.balls.back()->get_dimensions().height - 2;
    game_field.balls.back()->set_position(pos_x, pos_y);
}

void Game::Draw(RenderWindow &window) const {
    window.clear();
    window.draw(background);
    for (const auto& block : game_field.blocks)
        block->draw(window);
    game_field.platform.draw(window);
    if(game_field.is_safe_bottom){
        game_field.bottom.draw(window);
    }
    for (const auto& ball : game_field.balls){
        ball->draw(window);
    }
    for (const auto& bonus : bonuses) {
        bonus->draw(window);
    }
    for (const auto& block : game_field.moving_blocks){
        block->draw(window);
    }
    window.draw(score_text);
    window.display();

}

bool Game::OnEvent(Event &event, RenderWindow &window) {
    score_text.setString("SCORE:" + to_string(score));
    if(Keyboard::isKeyPressed((Keyboard::Space))){
        if(!game_field.platform.is_ordinary()){
            game_field.platform.change_magnet(game_field.balls);
        }
    }
    if(Keyboard::isKeyPressed(Keyboard::Escape)) {
        next_step = NextStep::START_MENU;
        return true;
    }
    if (Keyboard::isKeyPressed(Keyboard::Right)) move_platform(Keyboard::Right);
    if (Keyboard::isKeyPressed(Keyboard::Left)) move_platform(Keyboard::Left);

    move_blocks();
    move_bonuses();
    return move_balls();
}

bool Game::move_balls() {
    for (int ball_num = 0; ball_num < game_field.balls.size(); ball_num++) {
        move_ball_x(ball_num);
        move_ball_y(ball_num);
        if(game_field.blocks_num == 0){
            is_win = true;
            next_step = NextStep::END_WIN_MENU;
            return true;
        }
        shared_ptr<Ball> ball = game_field.balls[ball_num];
        Vector2f pos = ball->get_position();
        FloatRect size = ball->get_dimensions();

        if (pos.x < 0 || pos.x + size.width > background.getLocalBounds().width){
            float y = ball->get_position().y;
            if (pos.x < 0){
                ball->set_position(0, y);
            } else{
                ball->set_position(background.getLocalBounds().width-ball->get_dimensions().width,y);
            }
            ball->change_x();
        }
        if(pos.y > background.getLocalBounds().height){
            game_field.balls.erase(game_field.balls.begin() + ball_num);
            if(game_field.balls.empty()){
                is_win = false;
                next_step = NextStep::END_LOSE_MENU;
                return true;
            }
            ball->change_y();
        }
        if (pos.y < 0){
            ball->set_position(ball->get_position().x,0);
            ball->change_y();
        }
        if (ball->is_touch(game_field.platform)) {
            ball->change_y();
            if(!game_field.platform.is_ordinary()){
                game_field.platform.add_ball(ball);
                game_field.balls.erase(game_field.balls.begin() + ball_num);
                break;
            }
            ball->change_trajectory();
            float pos_y = game_field.platform.get_position().y - game_field.balls.back()->get_dimensions().height - 2;
            ball->set_position(ball->get_position().x, pos_y);
        }
        if(game_field.is_safe_bottom && ball->is_touch(game_field.bottom)){
            game_field.is_safe_bottom = false;
            ball->change_y();
            ball->change_trajectory();
            float pos_y = game_field.bottom.get_position().y - game_field.balls.back()->get_dimensions().height - 2;
            ball->set_position(ball->get_position().x, pos_y);
        }
    }
    return false;
}

void Game::move_platform(Keyboard::Key dir) {
    FloatRect bounds = background.getLocalBounds();
    game_field.platform.move(dir, bounds);
}

void Game::move_ball_x(int ball_num) {
    shared_ptr<Ball> ball = game_field.balls[ball_num];
    ball->move_x();
    for (int ball_num_extra = 0; ball_num_extra < game_field.balls.size(); ball_num_extra++){
        if(ball_num_extra == ball_num) continue;
        Ball& ball_extra = *game_field.balls[ball_num_extra];
        if (ball->is_touch(ball_extra)){
            ball->change_x();
            ball_extra.change_x();
            while (ball->is_touch(ball_extra)) {
                ball->move_x();
                ball_extra.move_x();
            }
        }
    }
    if(check_blocks(*ball)){
        ball->change_x();
        ball->move_x();
    }
}

void Game::move_ball_y(int ball_num) {
    shared_ptr<Ball> ball = game_field.balls[ball_num];
    ball->move_y();
    if(check_blocks(*ball)){
        ball->change_y();
        ball->move_y();
    }
    for (int ball_num_extra = 0; ball_num_extra < game_field.balls.size(); ball_num_extra++){
        if(ball_num_extra == ball_num) continue;
        Ball& ball_extra = *game_field.balls[ball_num_extra];
        if (ball->is_touch(ball_extra)){
            ball->change_y();
            ball_extra.change_y();
            while(ball->is_touch(ball_extra)) {
                ball->move_y();
                ball_extra.move_y();
            }
        }
    }

}

bool Game::check_blocks(Ball& ball) {
    for (int block_num = 0; block_num < game_field.blocks.size(); block_num++) {
        shared_ptr<Block> block = game_field.blocks[block_num];
        if (ball.is_touch(*block)) {
            if (block->get_health() != -1)score++;
            Views_of_Block scenery = block->touche_change();
            if (scenery == Views_of_Block::BONUS) {
                bonuses.push_back(make_shared<Bonus>());
                float pos_x = block->get_position().x + block->get_dimensions().width / 2 -
                              bonuses.back()->get_dimensions().width / 2;
                bonuses.back()->set_position(pos_x, block->get_position().y);
            } else if (scenery == Views_of_Block::SPEED_UP) {
                ball.change_speed(1.25);
            }
            if (block->get_health() == 0) {
                game_field.blocks_num--;
                game_field.blocks.erase(game_field.blocks.begin() + block_num);
            }
            return true;
        }
    }
    for(int block_num = 0; block_num < game_field.moving_blocks.size(); block_num++){
        auto block = game_field.moving_blocks[block_num];
        if(ball.is_touch(*block)){
            block->touche_change();
            if (block->get_health() == 0) {
                game_field.blocks_num--;
                game_field.moving_blocks.erase(game_field.moving_blocks.begin() + block_num);
            }
            score++;
            return true;
        }
    }
    return false;
}

void Game::move_bonuses() {
    for(int bonus_num = 0; bonus_num < bonuses.size(); bonus_num++){
        Bonus& bonus = *bonuses[bonus_num];
        bonus.set_position(bonus.get_position().x, bonus.get_position().y + 2);
        if(bonus.is_touch(game_field.platform)){
            bonus.operate(game_field);
            bonuses.erase(bonuses.begin() + bonus_num);
        }
        if(bonus.get_position().y > background.getLocalBounds().height){
            bonuses.erase(bonuses.begin() + bonus_num);
        }
    }

}

void Game::move_blocks() {
    for (int block_num = 0; block_num < game_field.moving_blocks.size();block_num++) {
        auto block = game_field.moving_blocks[block_num];
        block->move();
        for (int other_num = 0; other_num < game_field.moving_blocks.size();other_num++){
            auto other_block = game_field.moving_blocks[other_num];
            if(block_num != other_num && block->is_touch(*other_block)){
                block->change_dir();
                other_block->change_dir();
            }
        }
        if(block->get_position().x <= 0 || block->get_position().x+block->get_dimensions().width >= background.getLocalBounds().width){
            block->change_dir();
        }
    }

}


