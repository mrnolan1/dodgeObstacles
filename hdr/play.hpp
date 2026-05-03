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
#include "../hdr/bubble.hpp"
#include <sstream>
#include <iomanip>

class Play {
public:
    Play();
    ~Play() {};
    
    void setPlayerSkin(std::string file);
    void handleInput(sf::Event& event, sf::RenderWindow& window);
    screenState update(double dt);
    void oxygenUpdate(double dt);
    void render(sf::RenderWindow& window);

    void reset();

private:
    sf::Font mFont;
    sf::Text mTitle;

    sf::Sprite mBackground;
    sf::Texture mBackgroundTexture;
    Character mCharacter;
    Bubble mBubble;
    Row mRow[9];

    double mOxygen = 10.0;
    std::string mOxCnt = "Air: 10.000";
};