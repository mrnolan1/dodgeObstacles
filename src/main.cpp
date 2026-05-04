/** 
 * @file main.cpp 
 * @author Isaiah Preston 
 * @brief Main
 * @date 2026-03-17 
 */ 

#include <SFML/Graphics.hpp> 
#include <iostream> 
#include "../hdr/game.hpp" 

int main() 
{ 
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Game Test"); 
    Game Game;

    sf::Clock clock;

    //add dt later
    while (window.isOpen()) { 
        double dt = clock.restart().asSeconds();
        Game.handleInput(window); 
        Game.update(dt); 
        Game.render(window, dt);
    }  

    return 0;
}
