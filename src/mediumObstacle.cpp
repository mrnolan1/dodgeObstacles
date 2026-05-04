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
    if(!mTexture.loadFromFile("ast/spaceship.png")) {
        std::cout<<"Error opening file\n";
        exit(1);
    }

    if(!mTrailTexture.loadFromFile("ast/spaceship trail.png")) {
        std::cout<<"Error opening file\n";
        exit(1);
    }

    mCurSpeed = mMedSpeed;
    
    mSprite.setTexture(mTexture);
    mSprite.setScale(80.f/100, 80.f/100);
    mSprite.setPosition(1320.f, mRow * 80.f + 40.f);
    mSprite.setOrigin({50,50});

    mTrail.setTexture(mTrailTexture);
    mTrail.setScale(40.f/100, 40.f/100);
    mTrail.setOrigin({50,50});
    mTrail.setPosition(mSprite.getPosition().x -60 , mSprite.getPosition().y);
    mTrail.setColor({255, 255, 255, 70});
    
}

/**
 * @brief Update: called if medObs "picked" (in use)
 *          If first call, set "inUse", position, and speed
 *          Handle movement
 *          If moved off screen, position, stop speed, not "inUse", return not "inUse"
 * 
 * @return obsType 
 */
obsType mediumObstacle::update(double dt)
{
    if(!mIsInUse) {
        mIsInUse = true;
        mSprite.setPosition({-80.f, mRow * 80.f + 40.f});
        mCurSpeed = mMedSpeed;
    }

    mSprite.setPosition(mSprite.getPosition().x + mCurSpeed*dt, mSprite.getPosition().y);
    if(mSprite.getPosition().x == 1320.f && mSprite.getPosition().y == mRow * 80.f + 40.f)
    {
        mTrail.setPosition({1400.f, mRow * 80.f + 40.f});
    }
    else
    {
        mTrail.setPosition(mSprite.getPosition().x - 60, mSprite.getPosition().y);
    }
    
    if(mSprite.getPosition().x > 1400.f) {
        mSprite.setPosition({1320.f, mRow * 80.f + 40.f});
        mTrail.setPosition({1400.f, mRow * 80.f + 40.f});
        mCurSpeed = 0.0f;
        mIsInUse = false;
        return noObs;
    }

    return medObs;
}
