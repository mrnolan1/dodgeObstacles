/**
 * @file obstacle.hpp
 * @author Mathew & Justin
 * @brief 
 * @version 0.1
 * @date 2026-04-10
 * 
 * @copyright Copyright (c) 2026
 * 
 */
#ifndef OBSTACLE_HPP
#define OBSTACLE_HPP
#include <SFML/Graphics.hpp>
#include <iostream>

class Obstacle {
    public:

    Obstacle();
    ~Obstacle() {};
    //dt is delta time, the time passed since the last frame. Helps move obstacle.
    virtual void update() = 0;
    virtual void render(sf::RenderWindow& window) = 0;
    bool checkIfInCharColumn();

    protected:
    float mSpeed;
    sf::Sprite mSprite;
    sf::Texture mTexture;
    int mRow;
};



#endif