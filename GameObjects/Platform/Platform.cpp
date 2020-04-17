//
// Created by aleksei on 04.04.2020.
//

#include "Platform.h"

Platform::Platform() {
    font.loadFromFile("Fonts\\Text.ttf");
    set_texture("images\\Platform.jpg");
    text.setString("");
    change_size({0,0,300, 70});
}

void Platform::move(Keyboard::Key dir, FloatRect bounds) {
    Vector2f curPos = get_position();
    if((curPos.x <= 0 && dir == Keyboard::Left)  || (curPos.x + get_dimensions().width > bounds.width && dir == Keyboard::Right))
        return;
    float delta_x = dir == Keyboard::Right ? 6 : -6;
    set_position(curPos.x + delta_x, curPos.y);
    text.setPosition(curPos.x + delta_x - text.getLocalBounds().width/2 , curPos.y - text.getLocalBounds().height);
    for(const auto& ball : stuck_balls){
        Vector2f ball_pos = ball->get_position();
        ball->set_position(ball_pos.x + delta_x, ball_pos.y);
    }
}

void Platform::change_magnet(vector<shared_ptr<Ball>>& balls) {
    is_magnet = !is_magnet;
    if(is_magnet){
        text.setString("Press Space");
        stuck_balls.clear();
        set_texture("images\\Platform_MAGNET.jpg");
    } else{
        text.setString("");
        set_texture("images\\Platform.jpg");
        balls.reserve(balls.size()+stuck_balls.size());
        balls.insert(balls.end(),stuck_balls.begin(),stuck_balls.end());
        stuck_balls.clear();
    }
}
void Platform::add_ball(shared_ptr<Ball> ball) {
    stuck_balls.push_back(ball);
}

bool Platform::is_ordinary() {
    return !is_magnet;
}

void Platform::draw(RenderWindow &window) const {
    Object::draw(window);
    for(const auto& ball : stuck_balls){
        ball->draw(window);
    }
    window.draw(text);
}
