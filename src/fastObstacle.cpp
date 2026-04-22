/**
 * @file fastObstacle.cpp
 * @author Matthew, Justin
 * @brief FastObstacle class, child of Obstacle
 * @date 2026-04-11
 */

#include "../hdr/fastObstacle.hpp"

/**
 * @brief Construct a new fastObstacle::fastObstacle object
 *          Create sprite with asteroid texture
 *          Scale sprite to 50% of original size
 *          Set initial position of sprite
 */
fastObstacle::fastObstacle() {
    if(!mTexture.loadFromFile("assets/discord-icon.png")) {
        std::cout<<"Error opening file\n";
        exit(1);
    }

    mCurSpeed = mFastSpeed;

    mSprite.setTexture(mTexture);
    mSprite.setScale(66.7/100, 66.7/100); 
    mSprite.setPosition(1200.0f, mRow * 66.7f); 
}

/**
 * @brief Update: called if fastObs "picked" (in use)
 *          If first call, set "inUse", position, and speed
 *          Handle movement
 *          If moved off screen, position, stop speed, not "inUse", return not "inUse"
 * 
 * @return obsType 
 */
obsType fastObstacle::update(double dt) {
    if(!mIsInUse) {
        mIsInUse = true;
        mSprite.setPosition({-66.7f, mRow * 66.7f});
        mCurSpeed = mFastSpeed;
    }

    mSprite.setPosition(mSprite.getPosition().x + mCurSpeed*dt, mSprite.getPosition().y);

    if(mSprite.getPosition().x > 1200.0f) {
       mSprite.setPosition({1200.0f, mRow * 66.7f});
       mCurSpeed = 0.0f;
       mIsInUse = false;
       return noObs;
    }

    return fastObs;
}

/**
 * @brief Draw sprite to the window
 * 
 * @param window 
 */
void fastObstacle::render(sf::RenderWindow& window) {
    window.draw(mSprite); //draw sprite to window
}