#include <SFML/Graphics.hpp>
#include "Game/GameStartMenu.h"

#include "Game/GameApp.h"
#include "Game/Game.h"
#include "Game/EndGameMenu.h"

int main()
{
    RenderWindow window(sf::VideoMode(1332,850), "ARKANOID");
    GameApp* game = new GameStartMenu("images\\Start_Page.jpg");
    window.setFramerateLimit(100);

    while (window.isOpen()) {
        Event event{};
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
        }
        if(game->OnEvent(event,window)) {
            if(game->get_next() == NextStep::GAME) {
                game = new Game("images\\BackGround.jpg");
            } else if(game->get_next() == NextStep::START_MENU){
                game = new GameStartMenu("images\\Start_Page.jpg");
            } else if(game->get_next() == NextStep::END_LOSE_MENU){
                game = new EndGameMenu("images\\BadEnd.jpg", *(Game*)game);
            } else if(game->get_next() == NextStep::END_WIN_MENU){
                game = new EndGameMenu("images\\GoodEnd.jpg", *(Game*)game);
            }
        }
        game->Draw(window);
    }
    return 0;
}
