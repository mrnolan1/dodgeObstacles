
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
#include "../hdr/skins.hpp"
#include "../hdr/character.hpp"

int main() 
{ 
    sf::RenderWindow window(sf::VideoMode(800, 500), "Skins class test"); 
    Skins SkinMenu; 
    Character chara;
    while (window.isOpen()) 
   { 
       sf::Event event; 
       while (window.pollEvent(event)) 
       { 
           if (event.type == sf::Event::Closed) 
           { 
                window.close(); 
           } 
           SkinMenu.handleInput(event, window, chara); 
           SkinMenu.update(); 
       } 
       window.clear(); 
       SkinMenu.render(window); 
       window.display(); 

   } 

   return 1;
} 
