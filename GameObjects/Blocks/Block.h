#pragma once

#include <SFML/Graphics.hpp>
#include "../Object.h"
using std::vector;



/*!
 * \enum Views_of_Block
 * \brief Tells what to do after block touched.
 *
 */
enum class Views_of_Block{
    BONUS,///< Create bonus.
    SPEED_UP,///< Speed up a ball.
    NONE///< None
};

/*!
 * \class Block
 * \brief The class of Block.
 * \details The class provides the methods for blocks.
 */

class Block : public Object
{
protected:
	int health = 0;///< Number of touchings necessary to destroy block.
	Texture heart_texture;///< The texture of block's health.
	vector <Sprite> hearts;///< The array of block's health.
public:
    /*!
     * \brief Creates block.
     *
     * \details Creates block with 1-2 health.
     */
    Block();
    /*!
     * \brief Draw the block.
     * @param window The window where is the block.
     */
    void draw(RenderWindow& window) const;
    /*!
     * \brief Set the block's position.
     * @param x New abscissa.
     * @param y New ordinate.
     */
    void set_position(float x, float y) override;
    /*!
     * \brief Changes the block after it is touched.
     * @return What to do after the touching.
     */
	virtual Views_of_Block touche_change();
	/*!
	 * \brief Returns how much health remains.
	 * @return Health.
	 */
    int get_health() const;

};

