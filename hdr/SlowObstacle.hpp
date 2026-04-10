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