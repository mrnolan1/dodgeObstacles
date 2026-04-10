#ifndef SLOWOBSTACLE_HPP
#define SLOWOBSTACLE_HPP
#include "obstacle.hpp"

class slowObstacle : public Obstacle 
{
    public:
    slowObstacle();
    ~slowObstacle() {};

    obsType update();
    void render(sf::RenderWindow& window);
};

#endif