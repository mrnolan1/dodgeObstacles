/**
 * @file character.hpp
 * @author Isaiah Preston
 * @brief Create a character controlled by the player. 
 *          If the character and any obstacle ever overlaps, end the game.
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
    void update();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    int getRow();
    void reset();
    void setSkin(std::string file);

private:
    int mRow = -1;
    sf::Sprite mCharacter;
    sf::Texture mTexture;
};