//
// Created by aleksei on 12.04.2020.
//

#include "Moving_Block.h"

Moving_Block::Moving_Block() {
    health = 3;
    hearts.resize(health, Sprite(heart_texture));
    set_texture("images\\Move_Block.jpg");
}

void Moving_Block::move() {
    set_position(get_position().x + dx, get_position().y);
}

void Moving_Block::place(vector<shared_ptr<Block>>& blocks) {
    set_position(1, blocks.back()->get_position().y + get_dimensions().height + 5);

}

void Moving_Block::change_dir() {
    dx=-dx;
}
