/**
 * @file menu.hpp
 * @author Matthew Nolan
 * @brief Menu screen: display title, background, and buttons 
 *          to switch to other screens (play, controls, skins)
 * @date 2026-04-11
 */

#pragma once

#include "button.hpp"
#include <SFML/Graphics.hpp>

enum screenState {menu, play, controls, skins, over};

class Menu {
public:
    Menu();
    ~Menu() {};

    screenState handleInput(sf::Event& event, sf::RenderWindow& mWindow);
    void update(double dt);
    void moveBackground(double dt);
    void fadeInText(double dt);

    void render(sf::RenderWindow& window);

private:
    sf::Text mTitle;
    sf::Font mFont;
    sf::Sprite mBackground;

    sf::Sprite mSecondBackground;
    sf::Texture mBackgroundTexture;
    float mBackgroundCounter = 0;
    float mBackgroundCounter2 = -1280;
    double mColorCounter = 0.0;
    Button mPlay; 
    Button mControls;
    Button mSkins;
};