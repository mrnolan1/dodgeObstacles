#include <SFML/Graphics.hpp>
// #include "../hdr/slowObstacle.hpp"
// #include "../hdr/obstacle.hpp"
// #include "../hdr/mediumObstacle.hpp"
// #include "../hdr/fastObstacle.hpp"


// sf::RenderWindow window(sf::VideoMode(800, 500), "obstacle test");
// slowObstacle obstacle(0);
// mediumObstacle obstacle2(2);
// fastObstacle obstacle3(4);
// int main()
// {
// while(window.isOpen())
// {
//     sf::Event event;
//     while(window.pollEvent(event))
//     {
//         if(event.type == sf::Event::Closed)
//         {
//             window.close();
//         }
//     }
//     obstacle.update();
//     obstacle2.update();
//     obstacle3.update();
//     window.clear();
//     obstacle.render(window);
//     obstacle2.render(window);
//     obstacle3.render(window);
//     window.display();
// }
// return 0;
// }