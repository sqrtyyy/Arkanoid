//
// Created by aleksei on 04.04.2020.
//

#ifndef ARKANOID_ORDINARY_BLOCK_H
#define ARKANOID_ORDINARY_BLOCK_H

#include "Block.h"

/*!
 * \class Ordinary_Block
 * \brief Class for ordinary block
 *
 * \details The ordinary block is o block which does not have any properties. It's health is from 1 to 2.
 */
class Ordinary_Block: public Block {

public:
    /*!
     * \brief Creates ordinary block.
     */
    Ordinary_Block();
};


#endif //ARKANOID_ORDINARY_BLOCK_H
