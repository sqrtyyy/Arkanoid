//
// Created by aleksei on 06.04.2020.
//

#include "GameApp.h"


void GameApp::load_background(const string& background_texture_source) {
    background_texture.loadFromFile(background_texture_source);
    background = Sprite(background_texture);
    load_fonts();
    Init();
}

void GameApp::load_fonts() {
    fonts[0].loadFromFile("../Fonts/Title.ttf");
    fonts[1].loadFromFile("../Fonts/Text.ttf");


}

NextStep GameApp::get_next() const {
    return next_step;
}
