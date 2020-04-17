#pragma once
#include "Block.h"
#include "../../Main.h"
/*!
 * \class Bonus_Block
 * \brief Class for bonus blocks.
 * \details The bonus block is a block, after destroying which, the bonus is created and starts to
 * fall down.
 */
class Bonus_Block :
	public Block
{

public:
    /*!
     *\brief Creates Bonus block
     */
	Bonus_Block();
	/*!
	 * \brief Changes block after touching.
	 *
	 * \details Reduce the health. If the health is 0, returns Bonus, which means to
	 * create bonus.
	 * @return What to do.
	 */
	Views_of_Block touche_change() override;

	
};

