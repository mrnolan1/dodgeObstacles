/**
 * @file over.cpp
 * @author Isaiah Preston
 * @brief 
 * @date 2026-05-03
 */

#include "../hdr/over.hpp"

Over::Over() {
    if(!mFont.loadFromFile("ast/SPACE.ttf")) {
        std::cerr << "Error loading font file" << std::endl;
        exit(0);
    }

    if(!mBackgroundTexture.loadFromFile("ast/spacebackgroundbigger.png")) {
        std::cerr << "Error loading background file" << std::endl;
        exit(0);
    }

    mBackground.setTexture(mBackgroundTexture);

    // mTitle.setFont(mFont);
    // mTitle.setCharacterSize(100);
    // mTitle.setString("Skins");
    // mTitle.setOrigin(mTitle.getGlobalBounds().width/2, mTitle.getGlobalBounds().height/2);
    // mTitle.setPosition({640,50});
    // mTitle.setFillColor(sf::Color::White);

    // mExitButton.setText("Back");
    // mExitButton.setPosition({100, 65});
    // mExitButton.setSize({150, 80});
    // mExitButton.setColorTextNormal(sf::Color::White);
    // mExitButton.setTextSize(30);
    // mExitButton.setTextPosition({215,75}); 
   

}

// screenState Skins::handleInput(sf::Event& event,  sf::RenderWindow& mWindow)
// {
//     if (mSkin1Button.handleInput(event, mWindow))
//     {
//         mSkinType = "ast/alien.png";
//         mCurrentSkinText.setString("Your current skin is: Alien");
//     }
//     else if (mSkin2Button.handleInput(event, mWindow))
//     {
//         mSkinType = "ast/astronaut.png";
//         mCurrentSkinText.setString("Your current skin is: Astronaut");
//     }
//     else if (mSkin3Button.handleInput(event, mWindow))
//     {
//         mSkinType = "ast/dog.png";
//         mCurrentSkinText.setString("Your current skin is: Dog");
//     }
//     else if (mExitButton.handleInput(event, mWindow))
//     {
//         mExitButton.setButtonState(normal);
//         return menu;
//     }
//     return skins;

// }

// std::string Skins::getSkinType()
// {
//     return mSkinType;
// }

void Over::update() {
    mExitButton.update();
}

void Over::render(sf::RenderWindow& window)
{
    window.draw(mBackground);
    window.draw(mExitButton);
    // window.draw(mTitle);
}