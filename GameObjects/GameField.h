//
// Created by aleksei on 08.04.2020.
//

#ifndef ARKANOID_GAMEFIELD_H
#define ARKANOID_GAMEFIELD_H


#include "../GameObjects/Platform/Platform.h"

#include "../GameObjects/Ball/Ball.h"
#include <memory>

#include "Blocks/Block.h"
#include "Blocks/Ordinary_Block.h"
#include "Blocks/Moving_Block.h"
/*!
 * \struct GameField
 * \brief The struct includes the game objects and data.
 *
 * \details Includes blocks, carriage, bottom(if "safe bottom" bonus is active"), balls, moving blocks.
 */

struct GameField{
    vector<shared_ptr<Block>> blocks;///< Blocks.
    Platform platform;///< Carriage.
    Platform bottom;///< Safe bottom.
    vector<shared_ptr<Ball>> balls;///< Balls.
    vector<shared_ptr<Moving_Block>> moving_blocks;///< Moving blocks.
    bool is_safe_bottom = false;///< If bonus "safe bottom" is active.
    int blocks_num = 0;///< Number of blocks, that must be destroyed to win.
};

#endif //ARKANOID_GAMEFIELD_H
