//
// Created by aleksei on 06.04.2020.
//

#ifndef ARKANOID_GAME_H
#define ARKANOID_GAME_H

#include <SFML/Graphics.hpp>
#include "GameApp.h"

#include "../GameObjects/Blocks/Block.h"
#include "../GameObjects/Blocks/Ordinary_Block.h"
#include "../GameObjects/Blocks/Unbreakable_Block.h"
#include "../GameObjects/Blocks/Bonus_Block.h"


#include "../GameObjects/Platform/Platform.h"

#include "../GameObjects/Ball/Ball.h"

#include "../GameObjects/Bonuses/Bonus.h"
#include "../GameObjects/GameField.h"

//! Class for Game process
/*!
 * \class Game
 * \brief This class creates a game "Arkanoid".
 *
 * \details Provides the main game process(Arkanoid). Main objects of the game is blocks, ball, and
 * carriage. To win you should destroy all destroyable blocks by ball, which is moving through the
 * game field. It can bounce off three of the walls(top, right, left). If it touches the bottom wall
 * you lose. To avoid this you have a control by a carriage which is moving on the bottom of the screen.
 * Ball can bounce off the carriage.
 * Besides, the game has different types of blocks. <b> Ordinary block<\b> is block which has not
 * any properties. <b> Unbreakable block <\b> is block which can not be destroyed. <b> Bonus block <\b> is the
 * block, after destroying which the bonus will be created. <b> Speed block<\b> is block which speed up your ball
 * after it touches the block. <b>Moving block<\b> is block which moves.
 * Every block(except indestructible) has health(the number of times the ball should touch it before
 * destroying).
 * Game has bonuses: <b>speed up<\b> speeds up all balls, <b>slow down<\b> slow down all balls,
 * <b>extra ball<\b> adds the ball, <b>expand carriage<\b> expands carriage, <b>narrow carriage<\b> narrow
 * the carriage, <b>change trajectory<\b> changes the one's of the balls trajectory in random time,<b>magnet<\b>
 * after collecting it every ball will stick to the carriage, until user presses the SPACE.
 */

class Game: public GameApp {
private:
    bool is_win = false; ///< Tells us if user has won the game.
    int score = 0; ///< The amount of points, which user has gained.
private:
    GameField game_field; ///< The structure which consists of game objects(balls, blocks, etc.).
    vector<shared_ptr<Bonus>> bonuses; ///< The array of bonuses.
    Text score_text;///< The inscription, which shows the score.
private:
    /*!
     * \brief Function creates the blocks with random properties.
     */
    void init_blocks();
    /*!
     * \brief Moves all balls.
     * @return The result of moving(if the game has ended).
     */
    bool move_balls();

    /*!
     * \brief Moves platform.
     * @param dir The direction(Left or right), where the carriage should move.
     */
    void move_platform(Keyboard::Key dir);

    void Init() override;
    /*!
     * \brief Moves the ball horizontally.
     *
     * \details Moves one ball, which number is indicated, horizontally and operates if it has touched something.
     * @param ball_num The number of the ball.
     */
    void move_ball_x(int ball_num);
    /*!
     * \brief Moves the ball vertically.
     *
     * \details Moves one ball, which number is indicated, vertically and operates if it has touched something.
     * @param ball_num The number of the ball.
     */
    void move_ball_y(int ball_num);
    /*!
     * \brief Checks if any of the blocks is touched by the ball and change block is it necessary.
     * @param ball The ball.
     * @return If one of the block is touched.
     */
    bool check_blocks(Ball& ball);

    /*!
     * \brief Moves all of the bonuses.
     *
     * \details Moves bonuses and check if any of them is in touch with carriage. If carriage touches
     * the bonus, activate the effect of it.
     */
    void move_bonuses();

    /*!
     * \brief Moves the moving blocks.
     *
     * \details Moves all of the blocks. If one of them touches another, changes the both's directions of moving.
     */
    void move_blocks();
public:

    Game()= default;
    /*!
     * /brief Creates the game.
     *
     * \details Creates all of the game objects(blocks, balls, background and carriage).
     * @param background_texture_source The path to the image of the background.
     */
    explicit Game(const string& background_texture_source);
    /*!
     * \brief Operate the game.
     *
     * \details Changes the game state(moves all of the objects). If buttons <b>LEFT<\b> or <b>RIGHT<\b> are
     * pressed on the keyboard, the carriage should move. If <b>ESC<\b> is pressed, you will
     * be returned to the main menu.
     * @param event The action, which user has done.
     * @param window The window, where the game is run.
     * @return If the game ended.
     */
    bool OnEvent(Event &event, RenderWindow &window) override;
    /*!
     * \brief Draw the game.
     *
     * \details Draws all of the game objects. < b>Does not < \b> change anything.
     */
    void Draw(RenderWindow &window) const override;
    /*!
     * \brief Tells the number of points which the user has gain.
     * @return Score.
     */
    int get_score() const{ return score;};
    /*!
     * \brief Tells the result of the game(win or lose).
     * @return The result.
     */
    int get_result() const{ return is_win;};

};


#endif //ARKANOID_GAME_H
