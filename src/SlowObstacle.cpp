#include "../hdr/SlowObstacle.hpp"

slowObstacle::slowObstacle() 
{
    mSpeed = 0.2f;
    //create sprite w/ asteriod texture
    if(!mTexture.loadFromFile("assets/discord-icon.png"))
    {
        std::cout<<"Error opening file\n";
        exit(1);
    }
    //sf::Vector2u SlowObstacleSize = mTexture.getSize(); //set size of obstacle
    mSprite.setTexture(mTexture);
    mSprite.setScale(1.0f, 1.0f); //scale sprite to 50% of original size
    mSprite.setPosition(800.0f, mRow * 100.0f); //set initial position of sprite

}

obsType slowObstacle::update()
{
    if(!mIsInUse)
    {
        mIsInUse = true;
        mSprite.setPosition({0, mRow*100});
        mSpeed = 0.2f;
    }
   
    mSprite.setPosition(mSprite.getPosition().x + mSpeed, mSprite.getPosition().y); //move sprite to the right
    //check if sprite is off the screen
    if(mSprite.getPosition().x > 800.0f)
    {
        mSprite.setPosition({800.0f, mRow * 100.0f}); //stop moving if off screen
        mSpeed = 0.0f;
        mIsInUse = false;
        return noObs;
    }
    return slowObs;
}

void slowObstacle::render(sf::RenderWindow& window) 
{
    window.draw(mSprite); //draw sprite to window
}

