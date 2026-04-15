#include <SFML/Graphics.hpp>
#include "../hdr/slowObstacle.hpp"
#include "../hdr/obstacle.hpp"
#include "../hdr/mediumObstacle.hpp"
#include "../hdr/fastObstacle.hpp"

slowObstacle sObs;
mediumObstacle mObs;
fastObstacle fObs;

int Justin_main() {
    sf::RenderWindow window(sf::VideoMode(800, 500), "obstacle test");
    
    while(window.isOpen()) {
        sf::Event event;
        while(window.pollEvent(event)) 
            if(event.type == sf::Event::Closed)
                window.close();

        sObs.update();
        mObs.update();
        fObs.update();
        
        window.clear();
        
        sObs.render(window);
        mObs.render(window);
        fObs.render(window);
        
        window.display();
    }

    return 0;
}