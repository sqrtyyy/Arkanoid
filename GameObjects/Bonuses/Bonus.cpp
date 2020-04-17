//
// Created by aleksei on 04.04.2020.
//

#include "Bonus.h"

#include <memory>

using std::make_shared;

Bonus::Bonus() {
    type = (Bonus_t)(rand() % ((int)Bonus_t::END_BONUS_LIST));
    font.loadFromFile("../Fonts/Text.ttf");
    name.setFont(font);
    name.setCharacterSize(18);
    name.setOutlineThickness(2);
    if(type == Bonus_t::SPEED_UP){
        name.setString("speed up");
        set_texture("images\\bonus_SPEED_UP.png");
        name.setFillColor(sf::Color::Red);
    }
    if(type == Bonus_t::SLOW_DOWN) {
        name.setString("slow down");
        set_texture("images\\bonus_SLOW_DOWN.png");
        name.setFillColor(sf::Color::Blue);
    }
    if(type == Bonus_t::EXTRA_BALL) {
        name.setString("extra ball");
        set_texture("images\\bonus_EXTRA_BALL.png");
        name.setFillColor(sf::Color::Blue);
    }
    if(type == Bonus_t::EXPAND_CARRIAGE){
        name.setString("expand carriage");
        set_texture("images\\bonus_CHANGE_CARRIAGE.png");
        name.setFillColor(sf::Color::Blue);
    }
    if(type == Bonus_t::NARROW_CARRIAGE){
        name.setString("narrow carriage");
        set_texture("images\\bonus_CHANGE_CARRIAGE.png");
        name.setFillColor(sf::Color::Red);
    }
    if(type == Bonus_t::MAGNET){
        name.setString("magnet");
        set_texture("images\\bonus_MAGNET.png");
        name.setFillColor(sf::Color::Blue);
    }
    if(type == Bonus_t::ADD_MOVING_BLOCK){
        name.setString("moving block");
        set_texture("images\\bonus_ADD_MOVING_BLOCK.png");
        name.setFillColor(sf::Color::Red);
    }
    if(type == Bonus_t::SAFE_BOTTOM){
        name.setString("safe bottom");
        set_texture("images\\bonus_SAFE_BOTTOM.png");
        name.setFillColor(sf::Color::Blue);
    }
    if(type == Bonus_t::CHANGE_TRAJECTORY){
        name.setString("change trajectory");
        set_texture("images\\bonus_CHANGE_TRAJECTORY.png");
        name.setFillColor(sf::Color::Red);
    }


}

void Bonus::operate(GameField &gameField) {
    if(type == Bonus_t::SPEED_UP){
        for(const shared_ptr<Ball>& ball : gameField.balls){
            ball->change_speed(1.25);
        }
    }
    if(type == Bonus_t::SLOW_DOWN){
        for(const shared_ptr<Ball>& ball : gameField.balls){
            ball->change_speed(0.75);
        }
    }
    if(type == Bonus_t::EXTRA_BALL){
        gameField.balls.push_back(make_shared<Ball>());
        float pos_x = gameField.platform.get_position().x + gameField.platform.get_dimensions().width / 2 - gameField.balls.back()->get_dimensions().width / 2;
        float pos_y = gameField.platform.get_position().y - gameField.balls.back()->get_dimensions().height - 1;
        gameField.balls.back()->set_position(pos_x, pos_y);
    }
    if(type == Bonus_t::EXPAND_CARRIAGE){
        int new_width = static_cast<int>(gameField.platform.get_dimensions().width * 1.25);
        IntRect new_size = {0,0,new_width,static_cast<int>(gameField.platform.get_dimensions().height)};
        gameField.platform.change_size(new_size);
    }
    if(type == Bonus_t::NARROW_CARRIAGE){
        int new_width = static_cast<int>(gameField.platform.get_dimensions().width * 0.75);
        IntRect new_size = {0,0,new_width,static_cast<int>(gameField.platform.get_dimensions().height)};
        gameField.platform.change_size(new_size);
    }
    if(type == Bonus_t::MAGNET){
        if(gameField.platform.is_ordinary()){
            gameField.platform.change_magnet(gameField.balls);
        }
    }
    if(type == Bonus_t::ADD_MOVING_BLOCK){
        gameField.moving_blocks.push_back(make_shared<Moving_Block>());
        gameField.moving_blocks.back()->place(gameField.blocks);
        gameField.blocks_num++;

    }
    if(type == Bonus_t::SAFE_BOTTOM){
        gameField.is_safe_bottom = true;
    }
    if(type == Bonus_t::CHANGE_TRAJECTORY){
        gameField.balls.back()->set_change(20);
    }
}

void Bonus::draw(RenderWindow &window) const {
    Object::draw(window);
    window.draw(name);
}

void Bonus::set_position(float x, float y) {
    Object::set_position(x, y);
    float pos_x = get_position().x + get_dimensions().width / 2 - name.getLocalBounds().width / 2;
    float pos_y = get_position().y - name.getLocalBounds().height;
    name.setPosition(pos_x, pos_y);
}

