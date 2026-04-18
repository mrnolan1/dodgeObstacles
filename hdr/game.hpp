/**
 * @file game.hpp
 * @author Isaiah Preston
 * @brief Game class, hold current screen state to call each screen (class)
 * @date 2026-04-07
 */

#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "../hdr/menu.hpp"
#include "../hdr/play.hpp"
#include "../hdr/skins.hpp"

class Game {
public:
    Game();
    ~Game() {};
    void handleInput(sf::RenderWindow& window);
    void update(double dt);
    void render(sf::RenderWindow& window);
private:
    screenState mScreenState;
    Menu mMenuScreen;
    Play mPlayScreen;
    //Controls mControlsScreen;
    Skins mSkinsScreen;
};
