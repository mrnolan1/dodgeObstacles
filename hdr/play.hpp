/**
 * @file play.hpp
 * @author Isaiah Preston
 * @brief 
 * @date 2026-04-04
 */

#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "../hdr/character.hpp"
#include "../hdr/row.hpp"
//#include "../hdr/obstacle.hpp"

class Play {
public:
    Play(sf::RenderWindow& playWindow);
    ~Play() {};
    void handleInput(sf::Event& event, sf::RenderWindow& window);

private:
    sf::Sprite mBackground;
    sf::Texture mBackgroundTexture;
    Character mCharacter;
    sf::Texture mTextureBackground;
    Row mRow[5];
};