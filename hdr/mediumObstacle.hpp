#ifndef MEDIUMOBSTACLE_HPP
#define MEDIUMOBSTACLE_HPP
#include "obstacle.hpp"

class mediumObstacle : public Obstacle 
{
    public:
    mediumObstacle();
    ~mediumObstacle() {};

    obsType update();
    void render(sf::RenderWindow& window);
};

#endif