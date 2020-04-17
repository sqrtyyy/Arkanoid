//
// Created by aleksei on 06.04.2020.
//

#ifndef ARKANOID_GAMESTARTMENU_H
#define ARKANOID_GAMESTARTMENU_H

#include "GameApp.h"
#include "GameMenu.h"

/*!
 * \class GameStartMenu
 * \brief Main menu.
 *
 * \details The class which operates with main menu. Menu has only one button for starting the game.
 */

class GameStartMenu : public GameMenu {
private:
    /*!
     * \brief Inits buttons ets.
     */
    void Init() override;

public:
    /*!
     * \brief Look EndGameMenu.
     * @param background_texture_source
     */
    explicit GameStartMenu(const string& background_texture_source);

    bool OnEvent(Event &event, RenderWindow &window) override;

    void Draw(RenderWindow &window) const override;

};


#endif //ARKANOID_GAMESTARTMENU_H
