/**
 * @file over.hpp
 * @author Isaiah Preston
 * @brief 
 * @date 2026-05-03
 */

#pragma once

#include "button.hpp"
#include "menu.hpp"
#include <SFML/Graphics.hpp>

class Over
{
public:
    Over();
    ~Over() {};

    // screenState handleInput(sf::Event& event,  sf::RenderWindow& mWindow);
    void update();
    void render(sf::RenderWindow& window);

private:
    Button mExitButton;
    
    sf::Font mFont;
    sf::Text mGameOver;
    sf::Text mDiedBy;
    sf::Text mYourScore;
    sf::Text mHighScore;
    sf::Text mMenu;

    sf::Sprite mBackground;
    sf::Texture mBackgroundTexture;
};