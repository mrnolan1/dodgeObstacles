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
    sf::RenderWindow window(sf::VideoMode(800, 500), "Game Test"); 
    Game Game;

    //add dt later
    while (window.isOpen()) { 
        Game.handleInput(window); 
        Game.update(); 
        Game.render(window);
    }  

    return 0;
}
