//
// Created by aleksei on 04.04.2020.
//

#ifndef ARKANOID_BALL_H
#define ARKANOID_BALL_H

#include "../Object.h"
#include "../../Main.h"
#include <cmath>
#include <iostream>
/*!
 * \class Ball
 * \brief Operates with ball.
 *
 * \details The class which has functions for working with ball.
 */
class Ball: public Object {
private:
    int till_change = -1; ///< The time till the trajectory will change.
    double  speed = 5; ///< The speed of the ball.
    double  angle = 1; ///< Еhe angle at which the ball moves.
public:
    /*!
     * \brief Creates the ball
     */
    Ball();
    /*!
     * \brief Move the ball horizontally.
     */
    void move_x();
    /*!
     * \brief Move the ball vertically.
     */
    void move_y();
    /*!
     * \brief Changes the direction vertically.
     */
    void change_y();
    /*!
     * \brief Changes the direction horizontally.
     */
    void change_x();
    /*!
     * \brief Randomly changes the trajectory.
     */
    void change_trajectory();
    /*!
     * \brief Changes the speed of the ball.
     * @param extra_speed How many times it is necessary to increase speed.
     */
    void change_speed(double extra_speed);
    /*!
     * \brief Set the time till changing trajectory.
     * @param tick
     */
    void set_change(unsigned int tick);

};


#endif //ARKANOID_BALL_H
