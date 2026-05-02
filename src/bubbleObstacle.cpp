/**
 * @file bubbleObstacle.cpp
 * @author Isaiah Preston
 * @brief BubbleObstacle class, child of Obstacle
 * @date 2026-05-02
 */

#include "../hdr/bubbleObstacle.hpp"

void bubbleObstacle::displayPosition() {
    // std::cout << "\nbubble x: " << mSprite.getPosition().x
    //  << "\n y: " << mSprite.getPosition().y;
    std::cout << mRow << '\n';
}

/**
 * @brief Construct a new bubbleObstacle::bubbleObstacle object
 *          Create sprite with bubble texture
 *          Scale sprite to 80% of original size
 *          Set initial position of sprite
 */
bubbleObstacle::bubbleObstacle() {
    if(!mTexture.loadFromFile("ast/bubble.png")) {
        std::cout<<"Error opening file\n";
        exit(1);
    }

    mCurSpeed = mBubSpeed;

    mSprite.setTexture(mTexture);
    mSprite.setScale(80.f/100, 80.f/100);
    mSprite.setPosition(1280.f, mRow * 80.f); 
}

/**
 * @brief Update: called if BubObs "picked" (in use)
 *          If first call, set "inUse", position, and speed
 *          Handle movement
 *          If moved off screen, position, stop speed, not "inUse", return not "inUse"
 * 
 * @return obsType 
 */
obsType bubbleObstacle::update(double dt) {
    if(!mIsInUse) {
        mIsInUse = true;
        mSprite.setPosition({-80.f, mRow * 80.f});
        mCurSpeed = mBubSpeed;
    }

    mSprite.setPosition(mSprite.getPosition().x + mCurSpeed*dt, mSprite.getPosition().y);

    if(mSprite.getPosition().x > 1280.0f) {
       mSprite.setPosition({1280.0f, mRow * 80.f});
       mCurSpeed = 0.0f;
       mIsInUse = false;
       return noObs;
    }

    return bubObs;
}

/**
 * @brief Draw sprite to the window
 * 
 * @param window 
 */
void bubbleObstacle::render(sf::RenderWindow& window) {
    window.draw(mSprite); //draw sprite to window
}
