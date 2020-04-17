//
// Created by aleksei on 08.04.2020.
//

#ifndef ARKANOID_SPEED_BLOCK_H
#define ARKANOID_SPEED_BLOCK_H


#include "Block.h"
/*!
 * \class Speed_Block
 *
 * \brief Class for Speed up Blocks.
 *
 * \details Speed up block is a block after touching which the speed of the ball is increasing.
 */
class Speed_Block: public Block {
public:
    /*!
     * \brief Creating the speed block
     */
    Speed_Block();
    /*!
     * \brief Change the block after touching.
     *
     * \details If the speed up block is touched returns SPEED_UP, which means that the ball, that has touched
     * it has to increase it's speed.
     * @return
     */
    Views_of_Block touche_change() override;
};


#endif //ARKANOID_SPEED_BLOCK_H
