/**
 * @file FastObstacle.hpp
 * @author Mathew & Justin
 * @brief 
 * @version 0.1
 * @date 2026-04-10
 * 
 * @copyright Copyright (c) 2026
 * 
 */
#ifndef FASTOBSTACLE_HPP
#define FASTOBSTACLE_HPP
#include "obstacle.hpp"

class fastObstacle : public Obstacle 
{
    public:
    fastObstacle(int row);
    ~fastObstacle() {};

    void update();
    void render(sf::RenderWindow& window);
};

#endif