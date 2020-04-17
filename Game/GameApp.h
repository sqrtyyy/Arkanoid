//
// Created by aleksei on 06.04.2020.
//

#ifndef ARKANOID_GAMEAPP_H
#define ARKANOID_GAMEAPP_H

#include <SFML/Graphics.hpp>
#include "../GameObjects/Object.h"
using sf::Font;
using sf::Event;
/*!
 * \enum NextStep
 * \brief The enum which tells what should be opened.
 */
enum class NextStep{
    START_MENU,
    END_WIN_MENU,
    END_LOSE_MENU,
    GAME,
};

class GameApp {
protected:
    Sprite background; ///< The object of the background.
    Texture background_texture;///< The texture of the background.
    Font fonts[2];///< Two fonts, first is for titles, second is for ordinary text.
    NextStep next_step;///< What should be opened after this.
protected:
    /*!
     * \brief Loads fonts.
     */
    void load_fonts();
    /*!
     * \brief Loads the back_ground.
     *
     * \details Loads the background texture from the source from the path. Besides, calls the
     * virtual function Init.
     * @param background_texture_source The path to the background image.
     */
    void load_background(const string& background_texture_source);
    /*!
     * \brief Inits the window.
     *
     * \details Inits all of the params of the window. Every successor has it's own realisation
     * of this function.
     */
    virtual void Init() = 0;

public:
    virtual bool OnEvent(Event &event, RenderWindow &window) = 0;

    virtual void Draw(RenderWindow &window) const = 0;
    /*!
     * \brief Tells what should be opened next to provide the correct game process.
     * @return The type of next window.
     */
    NextStep get_next() const;

};


#endif //ARKANOID_GAMEAPP_H
