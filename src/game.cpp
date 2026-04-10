/**
 * @file game.cpp
 * @author Isaiah Preston
 * @brief 
 * @date 2026-04-07]
 */

#include "../hdr/game.hpp"

Game::Game() {
    mScreenState = menu;
}

void Game::handleInput(sf::RenderWindow& window) {
    sf::Event event;
    while(window.pollEvent(event)) {
        if(event.type == sf::Event::Closed)
            window.close();

        switch(mScreenState) {
            case menu: {
                mScreenState = mMenuScreen.handleInput(event, window);
                break;
            }
            case play: {
                mScreenState = mPlayScreen.handleInput(event, window);
                break;
            }
            //case howtoplay, and skins
        }
    }
}

void Game::update() {
    switch(mScreenState) {
        case menu: {
            mMenuScreen.update();
            break;
        }
        case play: {
            mPlayScreen.update();
            break;
        }
        //case howtoplay, and skins
    }
}

void Game::render(sf::RenderWindow& window) {
    window.clear();
    switch (mScreenState) {
        case menu: {
            mMenuScreen.render(window);
            break;
        } 
        case play: {
            mPlayScreen.render(window);
            break;
        }
        // case howtoplay: case skins:        
        }
    window.display();
}

