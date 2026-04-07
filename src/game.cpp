/**
 * @file game.cpp
 * @author Isaiah Preston
 * @brief 
 * @date 2026-04-07]
 */

#include "../hdr/game.hpp"

Game::Game(sf::RenderWindow& window) {
    mScreenState = menu;
}

void Game::handleInput(sf::RenderWindow& window) {
    sf::Event event;
    while(window.pollEvent(event)) {
        if(event.type == sf::Event::Closed)
            window.close();

        mScreenState = mMenu.handleInput(event, window);
    }
}

void Game::update(sf::RenderWindow& window, float dt) {

}
void Game::render(sf::RenderWindow& window) {

}