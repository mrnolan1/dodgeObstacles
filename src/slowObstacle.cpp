/**
 * @file slowObstacle.cpp
 * @author Matthew, Justin
 * @brief SlowObstacle class, child of Obstacle
 * @date 2026-04-11
 */

#include "../hdr/slowObstacle.hpp"

/**
 * @brief Construct a new slowObstacle::slowObstacle object
 *          Create sprite with asteroid texture
 *          Scale sprite to 50% of original size
 *          Set initial position of sprite
 */
slowObstacle::slowObstacle() {
    if(!mTexture.loadFromFile("assets/asteroid.png")) {
        std::cerr << "Error opening file\n";
        exit(1);
    }

    mCurSpeed = mSlowSpeed;

    mSprite.setTexture(mTexture);
    mSprite.setScale(80.f/100, 80.f/100);
    mSprite.setPosition(1280.f, mRow * 80.f);
    mSprite.setOrigin({50,50});
}

/**
 * @brief Update: called if slowObs "picked" (in use)
 *          If first call, set "inUse", position, and speed
 *          Handle movement
 *          If moved off screen, position, stop speed, not "inUse", return not "inUse"
 * 
 * @return obsType 
 */
obsType slowObstacle::update(double dt) {
    if(!mIsInUse) {
        mIsInUse = true;
        mSprite.setPosition({-80.f, mRow * 80.f});
        mCurSpeed = mSlowSpeed;
    }
   
    mSprite.setPosition(mSprite.getPosition().x + mCurSpeed*dt, mSprite.getPosition().y); 
    mSprite.setRotation(mSprite.getRotation()+mCurSpeed*dt);
    
    if(mSprite.getPosition().x > 1280.f) {
        mSprite.setPosition({1280.f, mRow * 80.f}); 
        mCurSpeed = 0.0f; 
        mIsInUse = false; 
        return noObs;
    }

    return slowObs;
}

/**
 * @brief Draw sprite to the window
 * 
 * @param window 
 */
void slowObstacle::render(sf::RenderWindow& window) {
    window.draw(mSprite);
}