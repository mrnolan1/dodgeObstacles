/**
 * @file menu.cpp
 * @author Matthew Nolan
 * @brief  
 * @date 
 */
#include <SFML/Graphics.hpp>
#include "../hdr/menu.hpp"
#include "../hdr/button.hpp"

/**
 * @brief Construct a new Menu:: Menu object
 * 
 */
Menu::Menu()
{
    if (!mFont.loadFromFile("assets/SPACE.ttf"))
    {
        std::cout<<"Error opening file\n";
        exit(2);
    }
    if (!mBackgroundTexture.loadFromFile("assets/space.jpg"))
    {
        std::cout<<"Error opening background file\n";
        exit(2);
    }
    mBackground.setTexture(mBackgroundTexture);
    mSecondBackground.setTexture(mBackgroundTexture);
    mBackground.setPosition({0,0});
    mSecondBackground.setPosition({-800, 0});

    mTitle.setFont(mFont);
    //choose the font size based on button size
    mTitle.setCharacterSize(60);
    //set label
    mTitle.setString("    Dodge\nObstacles!");
    mTitle.setOrigin(mTitle.getGlobalBounds().width/2, mTitle.getGlobalBounds().height/2);
    mTitle.setPosition({400,125});
    mTitle.setFillColor({0,0,0,0});
    
    mPlay.setText("Play");
    mPlay.setPosition({400, 400});
    mPlay.setSize({240, 100});
    mPlay.setColorTextNormal(sf::Color::White);
    mPlay.setTextPosition({465,400});

    mControls.setText("Controls");
    mControls.setPosition({150, 400});
    mControls.setSize({230, 71});
    mControls.setColorTextNormal(sf::Color::White);
    mControls.setTextSize(25);
    mControls.setTextPosition({380,415});

    mSkins.setText("Skins");
    mSkins.setPosition({650, 400});
    mSkins.setSize({230, 71});
    mSkins.setColorTextNormal(sf::Color::White);
    mSkins.setTextSize(25);
    mSkins.setTextPosition({780,415});
}
/**
 * @brief Handle input (which button did the user click?)
 * 
 * @param event 
 * @param window 
 * @return State 
 */
State Menu::handleInput(sf::Event& event, sf::RenderWindow& window)
{
    if (mPlay.handleInput(event, window)){
        return game;
    }
    else if (mControls.handleInput(event, window)){
        return howtoplay;
    }
    else if (mSkins.handleInput(event, window)){
        return skins;
    }
    return welcome;
}

/**
 * @brief update each button
 * 
 */
void Menu::update()
{
    mPlay.update();
    mControls.update();
    mSkins.update();
}

void Menu::moveBackground()
{
    if(mBackground.getPosition().x > 800)
    {
        mBackground.setPosition({-800,0});
        mBackgroundCounter = -800;
    }
    else if(mSecondBackground.getPosition().x > 800)
    {
        mSecondBackground.setPosition({-800,0});
        mBackgroundCounter2 = -800;
    }
    mBackgroundCounter = mBackgroundCounter + 0.5;
    mBackgroundCounter2 = mBackgroundCounter2 + 0.5;
    mBackground.setPosition({mBackgroundCounter, 0});
    mSecondBackground.setPosition({mBackgroundCounter2, 0});
}

void Menu::fadeInText()
{
    if (mColorCounter < 255)
    {
        mColorCounter++;
        mTitle.setFillColor({mColorCounter, mColorCounter, mColorCounter, mColorCounter});
    }
    std::cout << static_cast<int>(mColorCounter) << std::endl;
}
/**
 * @brief render each button
 * 
 * @param window 
 */
void Menu::render(sf::RenderWindow& window)
{
    window.draw(mBackground);
    window.draw(mSecondBackground);
    window.draw(mTitle);
    window.draw(mPlay);
    window.draw(mControls);
    window.draw(mSkins);
}
