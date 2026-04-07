/**
 * @file menu.hpp
 * @author Matthew Nolan
 * @brief  
 * @date 
 */

#include "button.hpp"
#include <SFML/Graphics.hpp>

enum screenState {menu, play, howtoplay, skins};

class Menu
{
public:
    Menu();
    screenState handleInput(sf::Event& event, sf::RenderWindow& mWindow);
    void update();
    void render(sf::RenderWindow& window);

private:
    sf::Text mTitle;
    sf::Font mFont;
    sf::Sprite mBackground;
    sf::Texture mBackgroundTexture;
    Button mPlay; 
    Button mControls;
    Button mSkins;
};