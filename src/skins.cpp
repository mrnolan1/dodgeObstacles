#include "../hdr/skins.hpp"
#include "../hdr/character.hpp"

Skins::Skins()
{
    if(!mSkin1Texture.loadFromFile("ast/alien.png"))
    {
        std::cerr << "Error loading skin1 file" << std::endl;
        exit(0);
    }
    if(!mSkin2Texture.loadFromFile("ast/astronaut.png"))
    {
        std::cerr << "Error loading skin2 file" << std::endl;
        exit(0);
    }
    if(!mSkin3Texture.loadFromFile("ast/dog.png"))
    {
        std::cerr << "Error loading skin3 file" << std::endl;
        exit(0);
    }
    if(!mFont.loadFromFile("ast/SPACE.ttf"))
    {
        std::cerr << "Error loading font file" << std::endl;
        exit(0);
    }
    if(!mBackgroundTexture.loadFromFile("ast/spacebackgroundbigger.png"))
    {
        std::cerr << "Error loading background file" << std::endl;
        exit(0);
    }

    mSkinType = "ast/astronaut.png"; 

    mBackground.setTexture(mBackgroundTexture);

    mSkin1.setTexture(mSkin1Texture);
    mSkin2.setTexture(mSkin2Texture);
    mSkin3.setTexture(mSkin3Texture);

    mCurrentSkin = mSkin1;

    mTitle.setFont(mFont);
    mTitle.setCharacterSize(100);
    mTitle.setString("Skins");
    mTitle.setOrigin(mTitle.getGlobalBounds().width/2, mTitle.getGlobalBounds().height/2);
    mTitle.setPosition({640,50});
    mTitle.setFillColor(sf::Color::White);

    mCurrentSkinText.setFont(mFont);
    mCurrentSkinText.setCharacterSize(30);
    mCurrentSkinText.setString("Your current skin is: Astronaut");
    mCurrentSkinText.setOrigin(mTitle.getGlobalBounds().width/2, mTitle.getGlobalBounds().height/2);
    mCurrentSkinText.setPosition({500,170});
    mCurrentSkinText.setFillColor(sf::Color::White);

    mSkin1.setPosition({360, 200});

    mSkin1Button.setText("Alien");
    mSkin1Button.setPosition({500, 400});
    mSkin1Button.setSize({320, 120});;
    mSkin1Button.setColorTextNormal(sf::Color::White);
    mSkin1Button.setTextSize(23);
    mSkin1Button.setTextPosition({525,415});

    mSkin2.setPosition({100, 200});

    mSkin2Button.setText("Astronaut");
    mSkin2Button.setPosition({200, 400});
    mSkin2Button.setSize({240, 60});
    mSkin2Button.setColorTextNormal(sf::Color::White);
    mSkin2Button.setTextSize(23);
    mSkin2Button.setTextPosition({424,415});

    mSkin3.setPosition({600, 200});

    mSkin3Button.setText("Dog");
    mSkin3Button.setPosition({650, 400});
    mSkin3Button.setSize({240, 60});
    mSkin3Button.setColorTextNormal(sf::Color::White);
    mSkin3Button.setTextSize(23);
    mSkin3Button.setTextPosition({740,415});

    mExitButton.setText("Back");
    mExitButton.setPosition({100, 65});
    mExitButton.setSize({150, 80});
    mExitButton.setColorTextNormal(sf::Color::White);
    mExitButton.setTextSize(30);
    mExitButton.setTextPosition({215,75}); 
   

}

screenState Skins::handleInput(sf::Event& event,  sf::RenderWindow& mWindow)
{
    if (mSkin1Button.handleInput(event, mWindow))
    {
        mSkinType = "ast/alien.png";
        mCurrentSkinText.setString("Your current skin is: Alien");
    }
    else if (mSkin2Button.handleInput(event, mWindow))
    {
        mSkinType = "ast/astronaut.png";
        mCurrentSkinText.setString("Your current skin is: Astronaut");
    }
    else if (mSkin3Button.handleInput(event, mWindow))
    {
        mSkinType = "ast/dog.png";
        mCurrentSkinText.setString("Your current skin is: Dog");
    }
    else if (mExitButton.handleInput(event, mWindow))
    {
        return menu;
    }
    return skins;

}

std::string Skins::getSkinType()
{
    return mSkinType;
}

void Skins::update()
{
    mSkin1Button.update();
    mSkin2Button.update();
    mSkin3Button.update();
    mExitButton.update();
}

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