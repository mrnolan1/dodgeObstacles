/** 
 * @file main.cpp 
 * @author Matthew Nolan 
 * @brief Main: create a Game to call functions with created window
 * @date 2026-03-17 
 */ 
#include <SFML/Graphics.hpp> 
#include <iostream> 
#include "../hdr/game.hpp" 

int main() 
{ 
    sf::RenderWindow window(sf::VideoMode(1200, 600), "Game Test"); 
    Game Game;

    sf::Clock clock;

    //add dt later
    while (window.isOpen()) { 
        double dt = clock.restart().asSeconds();
        Game.handleInput(window); 
        Game.update(dt); 
        Game.render(window);
    }  

    return 0;
}
