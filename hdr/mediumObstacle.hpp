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