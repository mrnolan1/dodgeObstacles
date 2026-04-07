/**
 * @file menu.hpp
 * @author Matthew Nolan
 * @brief  
 * @date 
 */

#ifndef MENU_HPP
#define MENU_HPP
#include "button.hpp"
#include <SFML/Graphics.hpp>

enum screenState {menu, play, howtoplay, skins};

class Menu
{
public:
    Menu();
    screenState handleInput(sf::Event& event, sf::RenderWindow& mWindow);
    void update();
    void moveBackground();
    void fadeInText();
    void render(sf::RenderWindow& window);

private:
    sf::Text mTitle;
    sf::Font mFont;
    sf::Sprite mBackground;
    sf::Sprite mSecondBackground;
    sf::Texture mBackgroundTexture;
    float mBackgroundCounter = 0;
    float mBackgroundCounter2 = 800;
    int mColorCounter = 0;
    Button mPlay; 
    Button mControls;
    Button mSkins;
};

#endif