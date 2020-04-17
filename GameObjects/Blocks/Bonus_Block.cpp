#include "Bonus_Block.h"

Views_of_Block Bonus_Block::touche_change() {
    Block::touche_change();
    return health != 0 ? Views_of_Block::NONE : Views_of_Block::BONUS;
}

Bonus_Block::Bonus_Block(){
    set_texture("images\\Lucky_block.jpg");
}
