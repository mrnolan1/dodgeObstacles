/**
 * @file button.cpp
 * @author Matthew Nolan
 * @brief Button class implementation file
 * @date 2026-03-17
 */
#include "../hdr/button.hpp"
#include <iostream>

/**
 * @brief Default constructor
 * 
 */
Button::Button()
{
    //set texture to button.png
    if (!mTexture.loadFromFile("assets/button.png"))
    {
        std::cout<<"Error opening file\n";
        exit(1);
    }

    //set font to SPACE.ttf
    if (!mFont.loadFromFile("assets/SPACE.ttf"))
    {
        std::cout<<"Error opening file\n";
        exit(2);
    }

    sf::Vector2u imageSize = mTexture.getSize();
    mButton.setTexture(mTexture);
    mButton.setOrigin({static_cast<float>(imageSize.x)/2, static_cast<float>(imageSize.y)/2});
    mButtonColor = sf::Color::White;
    mButton.setColor(mButtonColor);
    mPosition = {300,100};
    mButton.setPosition(mPosition.x, mPosition.y);
    mButton.setScale(1, 1);

    mText.setFont(mFont);
    mText.setString("Push me!");
    mText.setCharacterSize(mButton.getGlobalBounds().height/2.5);
    mText.setOrigin(mText.getGlobalBounds().width/2, mText.getGlobalBounds().height/2);
    mText.setPosition(mPosition.x, mPosition.y-(mButton.getGlobalBounds().width/4)/4);

    mTextNormal = sf::Color::Black;
    mTextHover = sf::Color::Red;

    mText.setFillColor(mTextNormal);
    mBtnState = normal;
}

/**
 * @brief Constructor
 * 
 * @param s The text on the button
 * @param position The position of the button
 * @param size The size of the button
 * @param color The color of the button
 */
Button::Button(std::string s, sf::Vector2f position, sf::Vector2f size, sf::Color color)
{
    //set texture to button.png
    if (!mTexture.loadFromFile("assets/button.png"))
    {
        std::cout<<"Error opening file\n";
        exit(1);
    }

    //set font to SPACE.ttf
    if (!mFont.loadFromFile("assets/SPACE.ttf"))
    {
        std::cout<<"Error opening file\n";
        exit(2);
    }

    sf::Vector2u imageSize = mTexture.getSize();
    mButton.setTexture(mTexture);
    mButton.setOrigin({static_cast<float>(imageSize.x)/2, static_cast<float>(imageSize.y)/2});
    mButtonColor = color;
    mButton.setColor(mButtonColor);
    mPosition = position;
    mButton.setPosition(mPosition.x, mPosition.y);
    mButton.setScale(size.x/imageSize.x, size.y/imageSize.y);

    mText.setFont(mFont);
    mText.setString(s);
    mText.setCharacterSize(mButton.getGlobalBounds().height/2.5);
    mText.setOrigin(mText.getGlobalBounds().width/2, mText.getGlobalBounds().height/2);
    mText.setPosition(mPosition.x, mPosition.y-(mButton.getGlobalBounds().width/4)/4);

    mTextNormal = sf::Color::Black;
    mTextHover = sf::Color::Red;

    mText.setFillColor(mTextNormal);
    mBtnState = normal;

}

/**
 * @brief Set the position of the button
 * 
 * @param position
 */
void Button::setPosition(sf::Vector2f position)
{
    mPosition.x = position.x;
    mPosition.y = position.y;
    sf::Vector2u imageSize = mTexture.getSize();
    mButton.setOrigin({static_cast<float>(imageSize.x)/2, static_cast<float>(imageSize.y)/2});
    mButton.setPosition(mPosition.x, mPosition.y);
    mText.setOrigin(mText.getGlobalBounds().width/2, mText.getGlobalBounds().height/2);
    mText.setPosition(mPosition.x, mPosition.y);
}

/**
 * @brief Set the size of the text
 * 
 * @param size 
 */
void Button::setTextSize(int  size)
{
    mText.setCharacterSize(size);
    mText.setPosition(mPosition.x+8, mPosition.y-5);
}

/**
 * @brief Set the position of the text
 * 
 * @param position 
 */
void Button::setTextPosition(sf::Vector2f position)
{
    mText.setPosition(position.x, position.y);
}

/**
 * @brief Set the size of the button
 * 
 * @param size 
 */
void Button::setSize(sf::Vector2f  size)
{
    sf::Vector2u imageSize = mTexture.getSize();
    mButton.setScale(size.x/imageSize.x, size.y/imageSize.y);
    mText.setCharacterSize(mButton.getGlobalBounds().height/2);
}

/**
 * @brief Set the color of the button
 * 
 * @param btnColor 
 */
void Button::setColor(sf::Color btnColor)
{
    mButton.setColor(btnColor);
}

/**
 * @brief Set the text on the button
 * 
 * @param s 
 */
void Button::setText(std::string s)
{
    mText.setString(s);
}
/**
 * @brief Update the screen when you hover over and click the button
 * 
 * @param e The event 
 * @param window The window
 */
void Button::update()
{
    switch (mBtnState)
    {
    case normal:
        mButton.setRotation(0);
        mText.setFillColor(mTextNormal);
        break;
    case hovered:
        mButton.setRotation(0);
        mText.setFillColor(mTextHover);
        break;
    case clicked:
        mButton.setRotation(180);
        mText.setFillColor(mTextHover);
        break;
    }
}

bool Button::handleInput(sf::Event& e, sf::RenderWindow& window)
{
    //get position of the mouse
    sf::Vector2i mPos = sf::Mouse::getPosition(window);
    sf::Vector2f mousePosition = window.mapPixelToCoords(mPos);
    bool mouseInButton =    mousePosition.x >= mButton.getPosition().x - mButton.getGlobalBounds().width/2
                            && mousePosition.x <= mButton.getPosition().x + mButton.getGlobalBounds().width/2
                            && mousePosition.y >= mButton.getPosition().y - mButton.getGlobalBounds().height/2
                            && mousePosition.y <= mButton.getPosition().y + mButton.getGlobalBounds().height/2;
    if(e.type == sf::Event::MouseMoved)
    {
        if(mouseInButton)
        {
            mBtnState = state::hovered;
        }
        else
        {
            mBtnState = state::normal;
        }
    }
    if (e.type == sf::Event::MouseButtonPressed)
    {
        if(e.mouseButton.button==sf::Mouse::Left)
        {
            if(mouseInButton)
            {
                mBtnState = state::clicked;
                return true;
            }
            else
            {
                mBtnState = state::normal;
            }
        }
    }
    if (e.type == sf::Event::MouseButtonReleased)
    {
        if (e.mouseButton.button==sf::Mouse::Left)
        {
            if(mouseInButton)
            {
                mBtnState = state::hovered;
            }
            else
            {
                mBtnState = state::normal;
            }
        }
    }
    return false;
    
}
    
/**
 * @brief Draw the button
 * 
 * @param target The window
 * @param states 
 */
void Button::draw(sf::RenderTarget& target,sf::RenderStates states) const
{
    target.draw(mButton, states);
    target.draw(mText, states);
}