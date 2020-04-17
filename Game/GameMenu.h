//
// Created by aleksei on 06.04.2020.
//

#ifndef ARKANOID_GAMEMENU_H
#define ARKANOID_GAMEMENU_H

#include "GameApp.h"
#include "Game.h"

class GameMenu: public GameApp {
protected:
    vector<Sprite> buttons; ///< Buttons which are used on menu.
    vector<Texture> buttons_texture; ///< Textures of the buttons.
    vector<Text> comments;///< The text information on the screen.
protected:
    void Init() override = 0;

public:
    bool OnEvent(Event &event, RenderWindow &window) = 0;

    void Draw(RenderWindow &window) const override;


};


#endif //ARKANOID_GAMEMENU_H
