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