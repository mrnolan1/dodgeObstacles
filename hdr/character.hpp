/**
 * @file character.hpp
 * @author Isaiah Preston
 * @brief Create a character class spawning in the center row, 
 *          left column. Allow movement with the arrow keys 
 *          up and down through the five rows on the screen. 
 *          Keep track of which row the character is in to be 
 *          compared to object rows later (game end if they 
 * @date 2026-04-02
 */

#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>
#include <iostream>

class Character : public sf::Drawable{
public:
    Character();
    ~Character() {};
    void moveUp();
    void moveDown();
    int getRow();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
private:
    int mRow;
    sf::Sprite mCharacter;
    sf::Texture mTexture;
};

#endif