//
// Created by aleksei on 04.04.2020.
//

#include "Ball.h"

int sign(double x) {
    return x > 0 ? 1 : -1;
}

double rand_angle(int a, int b){
    return (rand() %(b - a + 1) + a) * M_PI / 180;
}

Ball::Ball(){
    set_texture("images\\ball.png");
    angle = rand_angle(20, 160);
}
void Ball::move_x(){
    if(till_change >= 0){
        till_change -= rand()%2;
        if(till_change == -1){
            change_x();
            change_trajectory();
        }

    }
    Vector2f cur_pos = get_position();
    set_position(cur_pos.x + speed * cos(angle), cur_pos.y);
}

void Ball::move_y() {
    Vector2f cur_pos = get_position();
    set_position(cur_pos.x, cur_pos.y - speed * sin(angle));
}

void Ball::change_y() {
    angle = 2 * M_PI - angle;
}

void Ball::change_x() {
    angle += angle < M_PI ? M_PI : - M_PI;
    change_y();
}

void Ball::change_trajectory() {
    if(angle < M_PI / 2){
        angle = rand_angle(10,80);
    } else if(angle > 3 * M_PI / 2){
        angle = rand_angle(280,350);
    } else if (angle < M_PI){
        angle = rand_angle(100,170);
    } else if(angle < 3 * M_PI / 2){
        angle = rand_angle(190,260);
    }
}

void Ball::change_speed(double extra_speed) {
    speed *= extra_speed;
}

void Ball::set_change(unsigned int tick) {
    till_change = 200 / speed * (rand()%3 + 1);
}
