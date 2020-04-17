#include "Block.h"

Block::Block() {
    health = rand() % 2 + 1;
    heart_texture.loadFromFile("images\\Heart.png");
    hearts.resize(health, Sprite(heart_texture));
}

void Block::draw(RenderWindow &window) const {
    Object::draw(window);
    for(const Sprite& heart : hearts) {
        window.draw(heart);
    }
}

void Block::set_position(float x, float y) {
    Object::set_position(x, y);
    for(int i = 0; i < hearts.size(); i++){
        hearts[i].setPosition(get_position().x +  i * heart_texture.getSize().y, get_position().y);
    }
}

Views_of_Block Block::touche_change() {
    if(health < 1)
        return Views_of_Block::NONE;
    health--;
    hearts.erase(hearts.end());
    return Views_of_Block::NONE;
}

int Block::get_health() const {
    return health;
}
