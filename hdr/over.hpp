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
#include <cstdio>   // remove, rename
#include <fstream>
#include <sstream>

class Over
{
public:
    Over();
    ~Over() {mHighscoreFile.close();};

    screenState handleInput(sf::Event& event,  sf::RenderWindow& mWindow);
    void update();
    void setScreen(causeOfDeath cod, double score);
    void render(sf::RenderWindow& window);

private:
    Button mMenu;
    
    std::fstream mHighscoreFile;

    sf::Font mFont;
    sf::Text mGameOver;
    sf::Text mDiedBy;
    sf::Text mYourScore;
    sf::Text mHighscore;

    sf::Sprite mBackground;
    sf::Texture mBackgroundTexture;
};