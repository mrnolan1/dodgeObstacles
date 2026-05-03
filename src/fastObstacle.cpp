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
    if(!mTexture.loadFromFile("ast/ufo.png")) {
        std::cout<<"Error opening file\n";
        exit(1);
    }

    mCurSpeed = mFastSpeed;

    mSprite.setTexture(mTexture);
    mSprite.setScale(80.f/100, 80.f/100);
    mSprite.setPosition(1320.f, mRow * 80.f + 40.f); 
    mSprite.setOrigin({50,50});
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
        mSprite.setPosition({-80.f, mRow * 80.f + 40.f});
        mCurSpeed = mFastSpeed;
    }

    mSprite.setPosition(mSprite.getPosition().x + mCurSpeed*dt, mSprite.getPosition().y);

    if(mSprite.getPosition().x > 1320.0f) {
       mSprite.setPosition({1320.f, mRow * 80.f + 40.f});
       mCurSpeed = 0.0f;
       mIsInUse = false;
       return noObs;
    }

    return fastObs;
}