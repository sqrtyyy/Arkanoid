//
// Created by aleksei on 12.04.2020.
//

#ifndef ARKANOID_MOVING_BLOCK_H
#define ARKANOID_MOVING_BLOCK_H

#include "Block.h"
#include <memory>
using std::shared_ptr;
/*!
 * \class Moving_Block
 * \brief Class for block, that moves.
 *
 * \details Moving block has 3 health points and moves. If it touches another block, changes it direction.
 */
class Moving_Block:public Block {
private:
    float dx = 2;///< The speed of the block.
public:
    /*!
     * \brief Creates the moving block.
     */
    Moving_Block();
    /*!
     * \brief Moves the block.
     */
    void move();
    /*!
     * \brief Puts the block under blocks.
     * @param blocks
     */
    void place(vector<shared_ptr<Block>>& blocks);
    /*!
     * \brief Change the direction.
     */
    void change_dir();

};


#endif //ARKANOID_MOVING_BLOCK_H
