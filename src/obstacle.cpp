#include "obstacle.hpp"

Obstacle::Obstacle() 
{
    
}

void Obstacle::update()
{
    
}

void Obstacle::render(sf::RenderWindow& window) 
{
    
}


bool Obstacle::checkIfInCharColumn()
{   //check position of sprite row
    if(mSprite.getPosition().x >= 600.0f && mSprite.getPosition().x <= 800.0f)
    {
        return true;
    }
    else
    {
        return false;
    }
}

