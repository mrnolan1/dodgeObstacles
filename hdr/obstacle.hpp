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
    virtual ~Obstacle() {};

    virtual obsType update(double dt) = 0;
    void render(sf::RenderWindow& window);

    bool checkIfInCharColumn(); 
    void setRow(int row);
    void reset();

protected:
    float mCurSpeed = 0.f;

    sf::Sprite mSprite;
    sf::Texture mTexture;
    int mRow = -1;
    bool mIsInUse = false;
};
