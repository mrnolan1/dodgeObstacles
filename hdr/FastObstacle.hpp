/**
 * @file fastObstacle.hpp
 * @author Matthew, Justin
 * @brief FastObstacle class, child of Obstacle
 * @date 2026-04-11
 */

#pragma once

#include "obstacle.hpp"

class fastObstacle : public Obstacle {
public:
    fastObstacle();
    ~fastObstacle() {};
    obsType update();
    void render(sf::RenderWindow& window);
};