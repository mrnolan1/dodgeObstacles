/**
 * @file menu.hpp
 * @author Matthew Nolan
 * @brief  
 * @date 
 */
#include "states.hpp"
#include "button.hpp"
#include <SFML/Graphics.hpp>

class Menu
{
public:
    Menu();
    State handleInput(sf::Event& event,  sf::RenderWindow& mWindow);
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