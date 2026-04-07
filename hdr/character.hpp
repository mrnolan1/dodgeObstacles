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

#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

class Character : public sf::Drawable{
public:
    Character();
    ~Character() {};
    void handleInput(sf::Event& event, sf::RenderWindow& window);
    int getRow();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
private:
    int mRow;
    sf::Sprite mCharacter;
    sf::Texture mTexture;
};