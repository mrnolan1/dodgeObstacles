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
#ifndef HOWTOPLAY_HPP
#define HOWTOPLAY_HPP
#include "../hdr/menu.hpp"
#include "../hdr/button.hpp"
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

class HowToPlay {
public:
    HowToPlay();
    
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
    Button mInstructions;
};
//w move up s move down and space starts the game


#endif // HOWTOPLAY_HPP