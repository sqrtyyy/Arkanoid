//
// Created by aleksei on 06.04.2020.
//

#include "GameStartMenu.h"

using sf::Color;
using sf::Mouse;
using sf::Vector2i;

void GameStartMenu::Init() {
    Texture play_but_texture;
    play_but_texture.loadFromFile("images\\Play_Button.jpg");
    buttons_texture.push_back(play_but_texture);
    buttons.emplace_back(buttons_texture[0]);
    FloatRect bolds = background.getLocalBounds();
    float position_x = bolds.width / 2 - buttons[0].getLocalBounds().width / 2;
    float position_y = bolds.height / 2 + buttons[0].getLocalBounds().height / 2;
    buttons[0].setPosition(position_x, position_y);
}

bool GameStartMenu::OnEvent(Event &event, RenderWindow &window) {
    if (event.type == Event::MouseButtonPressed) {
        if (event.key.code == (Keyboard::Key)Mouse::Left) {
            Vector2i pos = Mouse::getPosition(window);
            if (buttons[0].getGlobalBounds().contains(pos.x, pos.y)) {
                next_step = NextStep::GAME;
                return true;
            }
        }
    }
    return false;


}

void GameStartMenu::Draw(RenderWindow &window) const {
    window.clear();
    window.draw(background);
    for(const auto& button : buttons){
        window.draw(button);
    }
    window.display();
}

GameStartMenu::GameStartMenu(const string &background_texture_source){
    load_background(background_texture_source);
}


