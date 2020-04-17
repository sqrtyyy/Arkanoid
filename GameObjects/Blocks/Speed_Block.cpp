//
// Created by aleksei on 08.04.2020.
//

#include "Speed_Block.h"

Speed_Block::Speed_Block() {
    set_texture("images\\block_Speed.jpg");
}

Views_of_Block Speed_Block::touche_change() {
    Block::touche_change();
    return Views_of_Block::SPEED_UP;
}
