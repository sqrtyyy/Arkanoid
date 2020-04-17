#include "Object.h"
using std::cout;
FloatRect Object::get_dimensions() const {
    return object.getGlobalBounds();
}


void Object::change_size(const IntRect new_dimensions) {
    object.setTextureRect(new_dimensions);
}

bool Object::is_touch(const Object &other_object) const {
    return this->get_dimensions().intersects(other_object.get_dimensions());
}

void Object::set_position(float x, float y) {
    object.setPosition(x, y);
}

Vector2f Object::get_position() {
    return object.getPosition();
}

void Object::draw(RenderWindow &window) const {
    window.draw(object);
}

void Object::set_texture(const string &image_path) {
    if(!texture.loadFromFile(image_path)){
        cout << "ERROR";
        return;
    }
    object.setTexture(texture);
}
