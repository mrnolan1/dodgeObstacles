#include "../hdr/game.hpp"
#include "../hdr/character.hpp"
#include "catch_amalgamated.hpp"
#include "../hdr/character.hpp"


sf::RenderWindow window(sf::VideoMode(1280, 720), "Test");

TEST_CASE("checkIfInCharColumn", "Obstacle class")
{
    slowObstacle obstacle;
    obstacle.setRow(1);
    CHECK(obstacle.checkIfInCharColumn() == false);
    obstacle.setPosition({1200.0f, 0.0f});
    CHECK(obstacle.checkIfInCharColumn() == true);

}

TEST_CASE("handleInput(sf::Event& event, sf::RenderWindow& window) ", "Character Class")
{
    Character character;
    sf::Event event;
    event.type = sf::Event::KeyPressed;
    SECTION("Down")
    {
        event.key.code = sf::Keyboard::Down;
        character.handleInput(event, window);
        CHECK(character.getRow() == 5);
    }


    SECTION("Up")
    {
        event.key.code = sf::Keyboard::Up;
        character.handleInput(event, window);
        CHECK(character.getRow() == 3);
    }
}


TEST_CASE("update()", "Character class")
{
    Character character;
    sf::Event event;
    character.update();
    CHECK(character.getPosition().x == 1240.0f); //starting position (row 4)
    CHECK(character.getPosition().y == 360.0f);
    event.type = sf::Event::KeyPressed;
    event.key.code = sf::Keyboard::Down;
    character.handleInput(event, window);
    character.update();
    CHECK(character.getPosition().x == 1240.0f); //row 5
    CHECK(character.getPosition().y == 440.0f);
}
