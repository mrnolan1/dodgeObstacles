/**
 * @file bubbleObstacle.hpp
 * @author Isaiah Preston
 * @brief BubbleObstacle class, must collect bubbles to stay alive
 * @date 2026-05-02
 */

#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <random>

class Bubble {
public:
    Bubble();
    ~Bubble() {};
    void update(double dt);
    void render(sf::RenderWindow& window);

    bool checkIfInCharColumn(int charRow); 
    void reset();
private:
    float mBubSpeed = 500.0f;
    int mRow = -1;
    sf::Sprite mSprite;
    sf::Texture mTexture;
};
