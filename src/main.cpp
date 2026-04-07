//this will be for the main file

#include <iostream>
#include <SFML/Graphics.hpp>
#include "../hdr/game.hpp"

int main()
{
   sf::RenderWindow window(sf::VideoMode(800, 500), "Video Game");
   Game videoGame(window);
   
    sf::Clock clock; 

    while(window.isOpen()) {
        float dt = clock.restart().asSeconds();
        videoGame.handleInput(window);
        videoGame.update(dt, window);
        videoGame.render(window);
    }

    return 0;
}

// int main() {
//    sf::RenderWindow window(sf::VideoMode(800, 500), "Video Game");
//    Game videoGame(window);

//     while(window.isOpen()) {
//         sf::Event event;
        
//         while (window.pollEvent(event)) {
//             if(event.type == sf::Event::Closed)
//                 window.close();
            
//             videoGame.handleInput(event, window);
//         }

//         window.clear();
//         videoGame.render(window);
//         window.display();
//     }
// }
