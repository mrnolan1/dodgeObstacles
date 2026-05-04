/**
 * @file skins.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2026-04-04
 * 
 * @copyright Copyright (c) 2026
 * 
 */
#pragma once

#include "button.hpp"
#include "menu.hpp"
#include "play.hpp"
#include <SFML/Graphics.hpp>

class Skins
{
public:
    Skins();
    screenState handleInput(sf::Event& event,  sf::RenderWindow& mWindow);
    std::string getSkinType();
    void update();
    void render(sf::RenderWindow& window);

private:
    Button mSkin1Button;
    Button mSkin2Button;
    Button mSkin3Button;
    sf::Sprite mSkin1;
    sf::Texture mSkin1Texture;
    sf::Sprite mSkin2;
    sf::Texture mSkin2Texture;
    sf::Sprite mSkin3;
    sf::Texture mSkin3Texture;

    Button mExitButton;

    sf::Text mTitle;
    sf::Text mCurrentSkinText;
    sf::Font mFont;
    sf::Sprite mBackground;
    sf::Texture mBackgroundTexture;

    std::string mSkinType;

};