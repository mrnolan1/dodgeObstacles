#include "../hdr/skins.hpp"
#include "../hdr/character.hpp"

Skins::Skins()
{
    if(!mSkin1Texture.loadFromFile("png/testCharacter copy.png"))
    {
        std::cerr << "Error loading skin1 file" << std::endl;
        exit(0);
    }
    if(!mSkin2Texture.loadFromFile("png/testCharacter copy 2.png"))
    {
        std::cerr << "Error loading skin2 file" << std::endl;
        exit(0);
    }
    if(!mSkin3Texture.loadFromFile("png/testCharacter copy 3.png"))
    {
        std::cerr << "Error loading skin3 file" << std::endl;
        exit(0);
    }
    if(!mFont.loadFromFile("assets/SPACE.ttf"))
    {
        std::cerr << "Error loading font file" << std::endl;
        exit(0);
    }
    if(!mBackgroundTexture.loadFromFile("assets/space.jpg"))
    {
        std::cerr << "Error loading background file" << std::endl;
        exit(0);
    }

    mBackground.setTexture(mBackgroundTexture);

    mSkin1.setTexture(mSkin1Texture);
    mSkin2.setTexture(mSkin2Texture);
    mSkin3.setTexture(mSkin3Texture);

    mCurrentSkin = mSkin1;

    mTitle.setFont(mFont);
    mTitle.setCharacterSize(60);
    mTitle.setString("Skins");
    mTitle.setOrigin(mTitle.getGlobalBounds().width/2, mTitle.getGlobalBounds().height/2);
    mTitle.setPosition({500,100});
    mTitle.setFillColor(sf::Color::White);

    mCurrentSkinText.setFont(mFont);
    mCurrentSkinText.setCharacterSize(20);
    mCurrentSkinText.setString("Your current skin is: Astronaut");
    mCurrentSkinText.setOrigin(mTitle.getGlobalBounds().width/2, mTitle.getGlobalBounds().height/2);
    mCurrentSkinText.setPosition({400,200});
    mCurrentSkinText.setFillColor(sf::Color::White);

    mSkin1.setPosition({400, 200});

    mSkin1Button.setText("Skin1");
    mSkin1Button.setPosition({400, 400});
    mSkin1Button.setSize({240, 100});
    mSkin1Button.setColorTextNormal(sf::Color::White);
    mSkin1Button.setTextPosition({400,400});

    mSkin2.setPosition({150, 200});

    mSkin2Button.setText("Skin2");
    mSkin2Button.setPosition({150, 400});
    mSkin2Button.setSize({240, 100});
    mSkin2Button.setColorTextNormal(sf::Color::White);
    mSkin2Button.setTextPosition({150,400});

    mSkin3.setPosition({650, 200});

    mSkin3Button.setText("Skin3");
    mSkin3Button.setPosition({650, 400});
    mSkin3Button.setSize({240, 100});
    mSkin3Button.setColorTextNormal(sf::Color::White);
    mSkin3Button.setTextPosition({650,400});

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
        mSkinType = "png/testCharacter copy.png";
        mCurrentSkinText.setString("Your current skin is: Astronaut");
    }
    else if (mSkin2Button.handleInput(event, mWindow))
    {
        mSkinType = "png/testCharacter copy 2.png";
        mCurrentSkinText.setString("Your current skin is: Alien");
    }
    else if (mSkin3Button.handleInput(event, mWindow))
    {
        mSkinType = "png/testCharacter copy 3.png";
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