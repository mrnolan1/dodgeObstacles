/**
 * @file howtoplay.hpp
 * @author Mathew & Justin
 * @brief 
 * @version 0.1
 * @date 2026-04-10
 * 
 * @copyright Copyright (c) 2026
 * 
 */
#pragma once

#include "../hdr/menu.hpp"
#include "../hdr/button.hpp"
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

class Controls {
public:
    Controls();
    
    screenState handleInput(sf::Event& event, sf::RenderWindow& window);
    void update();
    void moveBackground();
    void render(sf::RenderWindow& window);
private:
    //variables for the how to play screen
    sf::Text mTitle;
    sf::Font mFont;
    sf::Sprite mBackground;

    sf::Sprite mSecondBackground;
    sf::Texture mBackgroundTexture;
    float mBackgroundCounter = 0;
    float mBackgroundCounter2 = 800;
    Button mMenu;
    sf::Text mInstructions;
    sf::Text mInstructions2;
};
//w move up s move down and space starts the game
