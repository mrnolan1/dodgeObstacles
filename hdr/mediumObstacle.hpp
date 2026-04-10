/**
 * @file mediumObstacle.hpp
 * @author Mathew & Justin
 * @brief 
 * @version 0.1
 * @date 2026-04-10
 * 
 * @copyright Copyright (c) 2026
 * 
 */
#ifndef MEDIUMOBSTACLE_HPP
#define MEDIUMOBSTACLE_HPP
#include "obstacle.hpp"

class mediumObstacle : public Obstacle 
{
    public:
    mediumObstacle(int row);
    ~mediumObstacle() {};

    void update();
    void render(sf::RenderWindow& window);
};

#endif