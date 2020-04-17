cmake_minimum_required(VERSION 3.9)
project(Arkanoid)
set(CMAKE_CXX_STANDARD 20)
find_package(SFML 2.5.1 COMPONENTS system window graphics)

add_executable(Arkanoid main.cpp Main.h GameObjects/Object.cpp GameObjects/Object.h
        GameObjects/Blocks/Block.cpp GameObjects/Blocks/Block.h GameObjects/Blocks/Bonus_Block.cpp GameObjects/Blocks/Bonus_Block.h
        GameObjects/Blocks/Unbreakable_Block.h GameObjects/Blocks/Unbreakable_Block.cpp GameObjects/Platform/Platform.cpp
        GameObjects/Platform/Platform.h GameObjects/Ball/Ball.cpp GameObjects/Ball/Ball.h GameObjects/Blocks/Ordinary_Block.cpp
        GameObjects/Blocks/Ordinary_Block.h GameObjects/Bonuses/Bonus.cpp GameObjects/Bonuses/Bonus.h Game/GameApp.cpp
        Game/GameApp.h Game/GameStartMenu.cpp Game/GameStartMenu.h Game/Game.cpp Game/Game.h Game/EndGameMenu.cpp Game/EndGameMenu.h
        Game/GameMenu.cpp Game/GameMenu.h GameObjects/GameField.h GameObjects/Blocks/Speed_Block.cpp GameObjects/Blocks/Speed_Block.h
        GameObjects/Blocks/Moving_Block.cpp GameObjects/Blocks/Moving_Block.h)

add_executable(test main.cpp)

target_link_libraries(Arkanoid sfml-system sfml-window sfml-graphics)
target_link_libraries(test sfml-system sfml-window sfml-graphics)