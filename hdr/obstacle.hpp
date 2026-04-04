#ifndef OBSTACLE_HPP
#define OBSTACLE_HPP
#include <SFML/Graphics.hpp>

class Obstacle {
    public:

    Obstacle(float startY = 300.0f, float speed = 100.0f);
    virtual ~Obstacle() = default;//for inheritance

    void update(float deltaTime);
    void render(sf::RenderWindow& window);

    sf::FloatRect getBounds() const;//collision detection


    protected:
    sf::RectangleShape mshape;
    sf::Vector2f mVelocity;
    float mSpeed = 100.0f;
    sf::Sprite mSprite;
    sf::Texture mTexture;
    int mRow;
};

class slowObstacle : public Obstacle {
    slowObstacle(){
        mSpeed = 50.0f;
        mSprite = sf::SquareShape (100.0f, 100.0f);
        mTexture = Astroid;
        mRow = Random(0,5);
    }
};

#endif