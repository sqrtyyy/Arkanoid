#pragma once

#include "Block.h"
#include "../../Main.h"

/*!
 * \class Unbreakable_Block
 * \brief The class for unbreakable blocks.
 *
 * \details The unbreakable block can't be destroyed. It doesn't change after touching.
 */
class Unbreakable_Block : public Block
{
public:
    /*!
     * \brief Creates unbreakable block.
     */
    Unbreakable_Block();

};

