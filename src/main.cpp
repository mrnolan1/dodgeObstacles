/** 
 * @file main.cpp 
 * @author Matthew Nolan 
 * @brief  This program testing class button 
 * @date 2026-03-17 
 */ 
#include <SFML/Graphics.hpp> 
#include <iostream> 
#include "../hdr/menu.hpp" 
#include "../hdr/button.hpp" 

int main() 
{ 
    sf::RenderWindow window(sf::VideoMode(800, 500), "Menu class test"); 
    Menu mainMenu; 
    while (window.isOpen()) 
   { 
       sf::Event event; 
       while (window.pollEvent(event)) 
       { 
           if (event.type == sf::Event::Closed) 
           { 
                window.close(); 
           } 
           mainMenu.handleInput(event, window); 
           mainMenu.update(); 
       } 
       window.clear(); 
       mainMenu.moveBackground();
       mainMenu.fadeInText();
       mainMenu.render(window); 
       window.display(); 

   } 

} 