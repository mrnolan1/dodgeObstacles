/**
 * @file bubbleObstacle.hpp
 * @author Isaiah Preston
 * @brief BubbleObstacle class, child of Obstacle
 * @date 2026-05-02
 */

#pragma once

#include "obstacle.hpp"

class bubbleObstacle : public Obstacle {
public:
    bubbleObstacle();
    ~bubbleObstacle() {};
    obsType update(double dt);
    void render(sf::RenderWindow& window);

    void displayPosition();

private:
    float mBubSpeed = 500.0f;
};
