/**
 * @file mediumObstacle.cpp
 * @author Matthew, Justin
 * @brief MediumObstacle class, child of Obstacle
 * @date 2026-04-11
 */

#include "../hdr/mediumObstacle.hpp"

/**
 * @brief Construct a new mediumObstacle::mediumObstacle object
 *          Create sprite with asteroid texture
 *          Scale sprite to 50% of original size
 *          Set initial position of sprite
 */
mediumObstacle::mediumObstacle() {
    if(!mTexture.loadFromFile("assets/discord-icon.png")) {
        std::cout<<"Error opening file\n";
        exit(1);
    }

    mSpeed = 0.3f;
    
    mSprite.setTexture(mTexture);
    mSprite.setScale(1.0f, 1.0f);
    mSprite.setPosition(800.0f, mRow * 100.0f);
}

/**
 * @brief Update: called if medObs "picked" (in use)
 *          If first call, set "inUse", position, and speed
 *          Handle movement
 *          If moved off screen, position, stop speed, not "inUse", return not "inUse"
 * 
 * @return obsType 
 */
obsType mediumObstacle::update()
{
    if(!mIsInUse) {
        mIsInUse = true;
        mSprite.setPosition({0, mRow * 100.0f});
        mSpeed = 0.3f;
    }

    mSprite.setPosition(mSprite.getPosition().x + mSpeed, mSprite.getPosition().y);

    if(mSprite.getPosition().x > 800.0f) {
        mSprite.setPosition({800.0f, mRow * 100.0f});
        mSpeed = 0.0f;
        mIsInUse = false;
        return noObs;
    }

    return medObs;
}

/**
 * @brief Draw sprite to the window
 * 
 * @param window 
 */
void mediumObstacle::render(sf::RenderWindow& window) {
    window.draw(mSprite);
}
