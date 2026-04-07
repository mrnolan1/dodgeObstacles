#include "../hdr/mediumObstacle.hpp"

mediumObstacle::mediumObstacle(int row) 
{
    mSpeed = 0.5f;
    //create sprite w/ asteriod texture
    if(!mTexture.loadFromFile("assets/discord-icon.png"))
    {
        std::cout<<"Error opening file\n";
        exit(1);
    }
    
    mSprite.setTexture(mTexture);
    mSprite.setScale(1.0f, 1.0f); //scale sprite to 50% of original size
    mRow = row; //random row from 0-4
    mSprite.setPosition(0.0f, mRow * 100.0f); //set initial position of sprite

}

void mediumObstacle::update()
{
    mSprite.setPosition(mSprite.getPosition().x + mSpeed, mSprite.getPosition().y); //move sprite to the right
    //check if sprite is off the screen
    if(mSprite.getPosition().x > 800.0f)
    {
        mSpeed = 0.0f; //stop moving if off screen
    }
}

void mediumObstacle::render(sf::RenderWindow& window) 
{
    window.draw(mSprite); //draw sprite to window
}
