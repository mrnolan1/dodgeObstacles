/**
 * @file play.hpp
 * @author Isaiah Preston
 * @brief Play screen class. 
 *          Create background, character, 
 *          and rows (to hold obstacles)
 * @date 2026-04-04
 */

#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "../hdr/character.hpp"
#include "../hdr/row.hpp"
#include "../hdr/menu.hpp"

class Play {
public:
    Play();
    ~Play() {};
    
    void setPlayerSkin(std::string file);
    void handleInput(sf::Event& event, sf::RenderWindow& window);
    screenState update(double dt);
    void render(sf::RenderWindow& window);

    void reset();

private:
    sf::Sprite mBackground;
    sf::Texture mBackgroundTexture;
    Character mCharacter;
    Row mRow[9];
    // bool mBubExists = false;
};