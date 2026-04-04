#ifndef GAME_HPP
#define GAME_HPP
#include "obstacle.hpp"
#include <vector>
#include <SFML/Graphics.hpp>

class Game {
public:
    Game();           
    void run();       

private:
    void processEvents();  
    void update(float dt); 
    void render();         

    sf::RenderWindow mWindow;

    //Player stuff
    sf::RectangleShape m_player;
    float m_playerSpeed = 300.0f;//pixels per second
    //Obstacles stuff
    std::vector<Obstacle> m_obstacles;

protected:
    sf::RectangleShape m_shape;
    sf::Vector2f mVelocity;
};

#endif