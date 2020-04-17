//
// Created by aleksei on 06.04.2020.
//
#include "EndGameMenu.h"
using sf::Mouse;
using sf::Vector2i;
using sf::Color;
using std::to_string;


bool EndGameMenu::OnEvent(Event &event, RenderWindow &window) {
    if (event.type == Event::MouseButtonPressed) {
        if (event.key.code == (Keyboard::Key)Mouse::Left) {
            Vector2i pos = Mouse::getPosition(window);
            if (buttons[0].getGlobalBounds().contains(pos.x, pos.y)) {
                next_step = NextStep::GAME;
                return true;
            }
            pos = Mouse::getPosition(window);
            if (buttons[1].getGlobalBounds().contains(pos.x, pos.y)){
                next_step = NextStep::START_MENU;
                return true;
            }
        }
    }
    return false;
}

EndGameMenu::EndGameMenu(const string &backgroundTextureSource, Game &resultGame){
    score = resultGame.get_score();
    is_win = resultGame.get_result();
    load_background(backgroundTextureSource);
}

void EndGameMenu::Draw(RenderWindow &window) const {
   GameMenu::Draw(window);
}

void EndGameMenu::Init() {
    Texture restart_but_texture, title_screen_but_texture;
    restart_but_texture.loadFromFile("images\\RespawnButton.jpg");
    title_screen_but_texture.loadFromFile("images\\TitleScreenButton.jpg");
    buttons_texture.push_back(restart_but_texture);
    buttons_texture.push_back(title_screen_but_texture);

    buttons.emplace_back(buttons_texture[0]);
    buttons.emplace_back(buttons_texture[1]);

    FloatRect bolds = background.getLocalBounds();
    float position_x = bolds.width / 2 - buttons[0].getLocalBounds().width / 2;
    float position_y = bolds.height / 2 + buttons[0].getLocalBounds().height / 2;
    buttons[0].setPosition(position_x, position_y);
    position_y += buttons[0].getLocalBounds().height + 2;
    buttons[1].setPosition(position_x, position_y);
    comments.resize(2);
    comments[0].setFont(fonts[0]);
    comments[1].setFont(fonts[1]);
    if(is_win){
        comments[0].setString("Congratulations");
        comments[0].setCharacterSize(70);
        comments[0].setFillColor(Color::Green);
    } else{
        comments[0].setString("DEAD");
        comments[0].setCharacterSize(150);
        comments[0].setFillColor(Color::Red);
    }
    comments[1].setFillColor(Color::Blue);
    comments[0].setOutlineThickness(5);
    comments[1].setOutlineThickness(5);

    comments[1].setString("Your score: " + to_string(score));
    comments[1].setCharacterSize(100);
    comments[0].setPosition(bolds.width / 2 - comments[0].getLocalBounds().width / 2, bolds.height / 5);
    comments[1].setPosition(bolds.width / 2 - comments[1].getLocalBounds().width / 2, comments[0].getPosition().y + comments[0].getLocalBounds().height);



}
