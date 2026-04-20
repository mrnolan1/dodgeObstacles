/**
 * @file slowObstacle.hpp
 * @author Matthew, Justin
 * @brief SlowObstacle class, child of Obstacle
 * @date 2026-04-11
 */

#pragma once

#include "obstacle.hpp"

class slowObstacle : public Obstacle {
public:
    slowObstacle();
    ~slowObstacle() {};

    obsType update(double dt);
    void render(sf::RenderWindow& window);

private:
    float mSlowSpeed = 500.0f;
};