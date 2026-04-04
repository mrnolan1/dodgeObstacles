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