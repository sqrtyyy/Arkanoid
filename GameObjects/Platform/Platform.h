//
// Created by aleksei on 04.04.2020.
//

#ifndef ARKANOID_PLATFORM_H
#define ARKANOID_PLATFORM_H


#include "../Object.h"
#include "../Ball/Ball.h"
#include <memory>

using sf::Font;
using std::shared_ptr;
using std::vector;
using sf::Text;
using sf::Keyboard;
/*!
 * \class Platform
 * \brief The class for working with carriage.
 *
 * \details The class which provides the opportunity of changing the size of carriage, position etc.
 */
class Platform : public Object {
private:
    bool is_magnet = false; ///< Is carriage magnet.
    vector<shared_ptr<Ball>> stuck_balls;///< Balls which are stuck to the carriage.
    Font font;//
    Text text;
public:
    /*!
     * \brief Creates the carriage.
     *
     */
    Platform();
    /*!
     * \brief Moves the carriage.
     *
     * \details Moves the carriage according to the direction which is mentioned.If further movement
     * in the selected direction is not possible, does nothing.
     * @param dir The required direction.
     * @param bounds The bounds of the screen.
     */
    void move(Keyboard::Key dir, FloatRect bounds);
    /*!
     * \brief Change the sticking.
     *
     * \details If the carriage is in sticking mode, releases all of the balls, and changes the skin of
     * the carriage. If it is the normal mode, changes the texture carriage and if ball touches it,
     * carriage captures ball and moves with him.
     * @param balls The balls which are used in game.
     */
    void change_magnet(vector<shared_ptr<Ball>>& balls);
    /*!
     * \brief Add ball.
     * @param ball Ball which is stuck to the carriage.
     */
    void add_ball(shared_ptr<Ball> ball);
    /*!
     * \brief Checks if the carriage in normal mode.
     * @return If the carriage in normal mode.
     */
    bool is_ordinary();
    /*!
     * Draws the carriage.
     * @param window
     */
    void draw(RenderWindow& window) const override;
};


#endif //ARKANOID_PLATFORM_H
