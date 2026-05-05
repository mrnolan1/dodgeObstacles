/**
 * @file skins.cpp
 * @author Matthew Nolan
 * @brief Implementation for the skins screen
 * @date 2026-05-04
 */
#include "../hdr/skins.hpp"
#include "../hdr/character.hpp"

/**
 * @brief Default constructor for skins screen object
 * 
 */
Skins::Skins()
{
    //open the alien png file
    if(!mSkin1Texture.loadFromFile("ast/alien.png"))
    {
        std::cerr << "Error loading skin1 file" << std::endl;
        exit(0);
    }
    //open the astronaut png file
    if(!mSkin2Texture.loadFromFile("ast/astronaut.png"))
    {
        std::cerr << "Error loading skin2 file" << std::endl;
        exit(0);
    }
    //open the dog png file
    if(!mSkin3Texture.loadFromFile("ast/dog.png"))
    {
        std::cerr << "Error loading skin3 file" << std::endl;
        exit(0);
    }
    //open the font file
    if(!mFont.loadFromFile("ast/SPACE.ttf"))
    {
        std::cerr << "Error loading font file" << std::endl;
        exit(0);
    }
    //open the background file
    if(!mBackgroundTexture.loadFromFile("ast/spacebackgroundbigger.png"))
    {
        std::cerr << "Error loading background file" << std::endl;
        exit(0);
    }

    //set the default skin to astronaut
    mSkinType = "ast/astronaut.png"; 
    //set the background texture
    mBackground.setTexture(mBackgroundTexture);

    //set the textures for each skin sprite
    mSkin1.setTexture(mSkin1Texture);
    mSkin2.setTexture(mSkin2Texture);
    mSkin3.setTexture(mSkin3Texture);

    //set specifications for the title
    mTitle.setFont(mFont);
    mTitle.setCharacterSize(100);
    mTitle.setString("Skins");
    mTitle.setOrigin(mTitle.getGlobalBounds().width/2, mTitle.getGlobalBounds().height/2);
    mTitle.setPosition({640,50});
    mTitle.setFillColor(sf::Color::White);

    //set specifications for the current skin text
    mCurrentSkinText.setFont(mFont);
    mCurrentSkinText.setCharacterSize(30);
    mCurrentSkinText.setString("Your current skin is: Astronaut");
    mCurrentSkinText.setOrigin(mTitle.getGlobalBounds().width/2, mTitle.getGlobalBounds().height/2);
    mCurrentSkinText.setPosition({500,170});
    mCurrentSkinText.setFillColor(sf::Color::White);

    //set specifications for Skin1
    mSkin1.setScale(1.7, 1.7);
    mSkin1.setPosition({560, 250});

    mSkin1Button.setText("Alien");
    mSkin1Button.setPosition({640, 540});
    mSkin1Button.setSize({400, 120});;
    mSkin1Button.setColorTextNormal(sf::Color::White);
    mSkin1Button.setTextSize(40);
    mSkin1Button.setTextPosition({730,545});

    //set specifications for Skin2
    mSkin2.setScale(1.7, 1.7);
    mSkin2.setPosition({155, 250});

    mSkin2Button.setText("Astronaut");
    mSkin2Button.setPosition({230, 540});
    mSkin2Button.setSize({400, 120});
    mSkin2Button.setColorTextNormal(sf::Color::White);
    mSkin2Button.setTextSize(40);
    mSkin2Button.setTextPosition({425,545});

    //set specifications for Skin3
    mSkin3.setScale(1.7, 1.7);
    mSkin3.setPosition({980, 250});

    mSkin3Button.setText("Dog");
    mSkin3Button.setPosition({1050, 540});
    mSkin3Button.setSize({400, 120});
    mSkin3Button.setColorTextNormal(sf::Color::White);
    mSkin3Button.setTextSize(40);
    mSkin3Button.setTextPosition({1110,545});

    mExitButton.setText("Menu");
    mExitButton.setPosition({100, 65});
    mExitButton.setSize({150, 80});
    mExitButton.setColorTextNormal(sf::Color::White);
    mExitButton.setTextSize(30);
    mExitButton.setTextPosition({210,75}); 
   

}

/**
 * @brief Handle input for skins screen (Which button was selected?)
 * 
 */
screenState Skins::handleInput(sf::Event& event,  sf::RenderWindow& mWindow)
{
    //if skin1 button was clicked
    if (mSkin1Button.handleInput(event, mWindow))
    {
        //set skin type to alien and set the string
        mSkinType = "ast/alien.png";
        mCurrentSkinText.setString("Your current skin is: Alien");
    }
    //if skin2 button was clicked
    else if (mSkin2Button.handleInput(event, mWindow))
    {
        //set skin type to astronaut and set the string
        mSkinType = "ast/astronaut.png";
        mCurrentSkinText.setString("Your current skin is: Astronaut");
    }
    //if skin3 button was clicked
    else if (mSkin3Button.handleInput(event, mWindow))
    {
        //set skin type to dog and set the string
        mSkinType = "ast/dog.png";
        mCurrentSkinText.setString("Your current skin is: Dog");
    }
    //if exit button was clicked
    else if (mExitButton.handleInput(event, mWindow))
    {
        //set the exit button back to normal
        mExitButton.setButtonState(normal);
        //and return to the menu
        return menu;
    }

    //if nothing, stay on the skins screen
    return skins;

}

/**
 * @brief getter function for mSkinType
 * 
 * @return std::string 
 */
std::string Skins::getSkinType()
{
    return mSkinType;
}

/**
 * @brief Update the buttons on the skins screen
 * 
 */
void Skins::update()
{
    mSkin1Button.update();
    mSkin2Button.update();
    mSkin3Button.update();
    mExitButton.update();
}

/**
 * @brief Render everything for the skins screen
 * 
 */
void Skins::render(sf::RenderWindow& window)
{
    window.draw(mBackground);
    window.draw(mSkin1Button);
    window.draw(mSkin2Button);
    window.draw(mSkin3Button);
    window.draw(mExitButton);
    window.draw(mSkin1);
    window.draw(mSkin2);
    window.draw(mSkin3);
    window.draw(mTitle);
    window.draw(mCurrentSkinText);
}