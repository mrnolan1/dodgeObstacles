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
#include "../hdr/menu.hpp"
//#include "../hdr/obstacle.hpp"

class Play {
public:
    Play();
    ~Play() {};
    screenState handleInput(sf::Event& event, sf::RenderWindow& window);
    void update();
    void render(sf::RenderWindow& windwo);
private:
    sf::Sprite mBackground;
    sf::Texture mBackgroundTexture;
    Character mCharacter;
    Row mRow[5];
};