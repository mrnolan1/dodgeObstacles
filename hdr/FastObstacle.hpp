#ifndef FASTOBSTACLE_HPP
#define FASTOBSTACLE_HPP
#include "obstacle.hpp"

class fastObstacle : public Obstacle 
{
    public:
    fastObstacle();
    ~fastObstacle() {};
    obsType update();
    void render(sf::RenderWindow& window);
};

#endif