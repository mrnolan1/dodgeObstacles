/**
 * @file obstacle.cpp
 * @author Matthew, Justin
 * @brief Obstacle class, parent of other 3 Obstacle classes
 * @date 2026-04-11
 */

 #include "../hdr/obstacle.hpp"

/**
 * @brief If the obstacle of this row is in the 
 *          character column while the character 
 *          is in the obstacle's row, return true 
 *          (terminate game)
 * 
 * @return true 
 * @return false 
 */
bool Obstacle::checkIfInCharColumn() { 
    if(mSprite.getPosition().x > 625.0f && mSprite.getPosition().x < 775.0f)
        return true;
    else 
        return false;
}

/**
 * @brief Set the row of this obstacle
 * 
 * @param row 
 */
void Obstacle::setRow(int row) {
    mRow = row;
}

/**
 * @brief Set the position of all obstacles "off screen"
 * 
 */
void Obstacle::reset() {
    mSprite.setPosition(800.0f, mRow * 100.0f);
}

