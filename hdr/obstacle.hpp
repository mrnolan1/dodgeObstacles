#ifndef OBSTACLE_HPP
#define OBSTACLE_HPP
#include <SFML/Graphics.hpp>
#include <iostream>

class Obstacle {
    public:

    Obstacle();
    ~Obstacle() {};
    //dt is delta time, the time passed since the last frame. Helps move obstacle.
    virtual obsType update() = 0;
    virtual void render(sf::RenderWindow& window) = 0;
    bool checkIfInCharColumn(); 
    void setRow(int row);


    protected:
    float mSpeed;
    sf::Sprite mSprite;
    sf::Texture mTexture;
    int mRow;
    bool mIsInUse
};



#endif