/**
 * @file game.cpp
 * @author Isaiah Preston
 * @brief Game class, hold current screen state to call each screen (class)
 * @date 2026-04-07
 */

#include "../hdr/game.hpp"

/**
 * @brief Construct a new Game::Game object
 *          Initialize screen to menuScreen
 */
Game::Game() {
    mScreenState = menu;
}

/**
 * @brief Switch statement calling each screen depending on the current screen state
 * 
 * @param window 
 */
void Game::handleInput(sf::RenderWindow& window) {
    sf::Event event;
    while(window.pollEvent(event)) {
        if(event.type == sf::Event::Closed)
            window.close();

        switch(mScreenState) {
            case menu:
                mScreenState = mMenuScreen.handleInput(event, window);
                if(mScreenState == play) 
                    mPlayScreen.reset();
                break;
            case play:
                mPlayScreen.handleInput(event, window);
                break;
            case controls:
                mScreenState = mControlsScreen.handleInput(event, window);
                break;
            case skins:
                mScreenState = mSkinsScreen.handleInput(event, window);
                break;
            case over:
                mScreenState = mOverScreen.handleInput(event, window);
                break;
        }
    }
}

/**
 * @brief Update the screen based on the current screen state
 */
void Game::update(double dt) {
    switch(mScreenState) {
        case menu:
            mMenuScreen.update(dt);
            break;
        case play:
            mScreenState = mPlayScreen.update(dt);
            break;
        case controls:
            mControlsScreen.update();
            break;
        case skins:
            mPlayScreen.setPlayerSkin(mSkinsScreen.getSkinType());
            mSkinsScreen.update();
            break;
        case over:
            mOverScreen.update();
            break;
    }
}

/**
 * @brief Render based upon which screen is currently active (screen state)
 * 
 * @param window 
 */
void Game::render(sf::RenderWindow& window, double dt) {
    window.clear();
    switch (mScreenState) {
        case menu:
            mMenuScreen.render(window);
            mMenuScreen.fadeInText(dt);
            break;
        case play:
            mPlayScreen.render(window);
            break;
        case controls:
            mControlsScreen.render(window);
            break;
        case skins:
            mSkinsScreen.render(window);
            break;
        case over:
            mOverScreen.render(window);
            break;
    }
    window.display();
}

