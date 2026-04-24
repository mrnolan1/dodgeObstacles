/**
 * @file SlowObstacle.hpp
 * @author Mathew & Justin
 * @brief 
 * @version 0.1
 * @date 2026-04-10
 * 
 * @copyright Copyright (c) 2026
 * 
 */
#ifndef SLOWOBSTACLE_HPP
#define SLOWOBSTACLE_HPP
#include "obstacle.hpp"

class slowObstacle : public Obstacle 
{
    public:
    slowObstacle(int row);
    ~slowObstacle() {};

    void update();
    void render(sf::RenderWindow& window);
};

#endif