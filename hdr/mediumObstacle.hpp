/**
 * @file mediumObstacle.hpp
 * @author Matthew, Justin
 * @brief MediumObstacle class, child of Obstacle
 * @date 2026-04-11
 */

#pragma once

#include "obstacle.hpp"

class mediumObstacle : public Obstacle {
public:
    mediumObstacle();
    ~mediumObstacle() {};

    obsType update(double dt);
    void render(sf::RenderWindow& window);

private:
    float mMedSpeed = 1000.0f;
};