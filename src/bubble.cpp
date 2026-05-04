/**
 * @file bubbleObstacle.cpp
 * @author Isaiah Preston
 * @brief BubbleObstacle class, must collect bubbles to stay alive
 * @date 2026-05-02
 */

#include "../hdr/bubble.hpp"

/**
 * @brief Construct a new bubbleObstacle::bubbleObstacle object
 *          Create sprite with bubble texture
 *          Scale sprite to 80% of original size
 *          Set initial position of sprite
 */
Bubble::Bubble() {
    if(!mTexture.loadFromFile("ast/bubble.png")) {
        std::cout<<"Error opening file\n";
        exit(1);
    }

    mSprite.setTexture(mTexture);
    mSprite.setScale(80.f/100, 80.f/100);
    mSprite.setPosition(1320.f, 0); 
    mSprite.setOrigin({50,50});
}

/**
 * @brief constantly keep cycling one bubble. when it goes off screen, position it to a new spot
 * 
 * @return obsType 
 */
void Bubble::update(double dt) {
    if(mSprite.getPosition().x > 1320.0f) {
        static std::random_device rd;                   // a seed source for the random number engine
        static std::mt19937 gen(rd());                  // mersenne_twister_engine seeded with rd()
        std::uniform_int_distribution<> dist(0, 8);     // Use distrib to transform the random unsigned int
        mRow = dist(gen);
        mSprite.setPosition({-80.f, mRow * 80.f + 40.f});
    }

    mSprite.setPosition(mSprite.getPosition().x + mBubSpeed*dt, mSprite.getPosition().y);

    float mPulseSpeed = dt*15;
    if(mSprite.getScale().x < 60.f/100 && mSprite.getScale().y < 60.f/100)
    {
        mPulse = false;
    }
    else if (mSprite.getScale().x > 80.f/100 && mSprite.getScale().y > 80.f/100)
    {
        mPulse = true;
    }

    if(mCounter % 25 == 0 && mPulse == true)
    {
        mSprite.setScale(mSprite.getScale().x - mPulseSpeed, mSprite.getScale().y - mPulseSpeed);
    }
    else if(mCounter % 25 == 0 && mPulse == false)
    {
        mSprite.setScale(mSprite.getScale().x + mPulseSpeed, mSprite.getScale().y + mPulseSpeed);
    }

    mCounter--;
    if(mCounter == 0)
    {
        mCounter = 10000;
    }
}

/**
 * @brief Draw sprite to the window
 * 
 * @param window 
 */
void Bubble::render(sf::RenderWindow& window) {
    window.draw(mSprite); //draw sprite to window
}

void Bubble::reset() {
    mSprite.setPosition(1320.f, 0.f);
}

bool Bubble::checkIfInCharColumn(int charRow) { 
    if((1160.f < mSprite.getPosition().x && mSprite.getPosition().x < 1320.f) 
        && (mRow == charRow)) {
            
        mSprite.setPosition(mSprite.getPosition().x + 160.f, mSprite.getPosition().y);
        return true;
    } else {
        return false;
    }
}