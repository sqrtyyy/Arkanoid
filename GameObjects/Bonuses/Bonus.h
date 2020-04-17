//
// Created by aleksei on 04.04.2020.
//

#ifndef ARKANOID_BONUS_H
#define ARKANOID_BONUS_H

#include "../Object.h"
#include "../GameField.h"

/*!
 * \class Bonus
 * \brief Bonus and it effects.
 *
 * \details Class for operating with bonuses.
 */
class Bonus : public Object {
private:
    /*!
     * \enum Bonus_t
     * \brief The type of bonus.
     *
     * \details The enum which includes the types of bonuses. Every type is unique.
     */
    enum class Bonus_t
    {
        SPEED_UP, ///< Speeds up the balls.
        SLOW_DOWN,///< Slows down the balls.
        EXTRA_BALL,///< Adds one ball.
        EXPAND_CARRIAGE,///< Expands the carriage.
        NARROW_CARRIAGE,///< Narrows the carriage.
        MAGNET,///< Change the sticking of the carriage.
        ADD_MOVING_BLOCK,///< Adds the moving block.
        SAFE_BOTTOM,///< Adds the platform on the bottom, which disappears after touching.
        CHANGE_TRAJECTORY,///< Changes the trajectory of one of the balls.
        END_BONUS_LIST///< End of the bonuses.
    };
private:
    Bonus_t type;///< The type of the bonus.
    Text name;///< The name of the bonus.
    Font font;///< The font of the bonus name.
public:
    /*!
     * \brief Creates the bonus.
     *
     * \details Creates the bonus with a random type.
     */
    Bonus();
    /*!
     * \brief Activates the bonus effect.
     *
     * \details Changes game objects according to bonus type.
     * @param gameField The game objects.
     */
    void operate(GameField& gameField);
    /*!
     * \brief Draws bonus.
     *
     * \details Draws the bonus and it's name on top of it. If the bonus is good it's name color is blue
     * if is not - red.
     * @param window The window of the game.
     */
    void draw(RenderWindow& window) const override;
    /*!
     * \brief Set position of the bonus
     * @param x New abscissa.
     * @param y New ordinate.
     */
    void set_position(float x, float y) override;
};


#endif //ARKANOID_BONUS_H
