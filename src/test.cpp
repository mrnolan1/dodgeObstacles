#include "../hdr/game.hpp"
#include "../hdr/character.hpp"
#include "catch_amalgamated.hpp"
#include "../hdr/character.hpp"


sf::RenderWindow window(sf::VideoMode(1280, 720), "Test");




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
    CHECK(character.getPosition() == sf::Vector2f(1200, 320)); //starting position (row 4)
    event.type = sf::Event::KeyPressed;
    event.key.code = sf::Keyboard::Down;
    character.handleInput(event, window);
    character.update();
    CHECK(character.getPosition() == sf::Vector2f(1200, 400)); //row 5
}
