/**
 * @file obstacle.hpp
 * @author Matthew, Justin
 * @brief Obstacle class, parent of other 3 Obstacle classes
 * @date 2026-04-11
 */

#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

enum obsType {noObs, slowObs, medObs, fastObs};

class Obstacle {
public:
    Obstacle() {};
    ~Obstacle() {};

    virtual obsType update(double dt) = 0;
    virtual void render(sf::RenderWindow& window) = 0;

    bool checkIfInCharColumn(); 
    void setRow(int row);
    void reset();

protected:
    float mSpeed;
    sf::Sprite mSprite;
    sf::Texture mTexture;
    int mRow;
    bool mIsInUse;
};
