/**
 * @file game.hpp
 * @author Isaiah Preston
 * @brief 
 * @date 2026-04-07
 */

#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "../hdr/menu.hpp"

class Game {
public:
    Game(sf::RenderWindow& window);
    ~Game() {};
    void handleInput(sf::RenderWindow& window);
    void update(sf::RenderWindow& window, float dt, );
    void render();
private:
    Menu mMenu;
    screenState mScreenState;
};