
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
#include "../hdr/play.hpp"

class Game {
public:
    Game();
    ~Game() {};
    void handleInput(sf::RenderWindow& window);
    void update();
    void render(sf::RenderWindow& window);
private:
    screenState mScreenState;
    Menu mMenuScreen;
    Play mPlayScreen;
    //howtoplay
    //skins
};
