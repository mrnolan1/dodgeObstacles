#include "obstacle.hpp"

Obstacle::Obstacle(float startY, float speed) {
    mshape.setSize(sf::Vector2f(100.0f, 100.0f));
    mVelocity = sf::Vector2f(speed, 0.0f);//move right by default

    //start at the right edge of the window
    mshape.setPosition(1.0f, startY);
}

void Obstacle::update(float deltaTime) {
    // Move the obstacle based on its velocity and the elapsed time
    mshape.move(mVelocity * deltaTime);
}

void Obstacle::render(sf::RenderWindow& window) {
    window.draw(mshape);
}

sf::FloatRect Obstacle::getBounds() const {
    return mshape.getGlobalBounds();
}