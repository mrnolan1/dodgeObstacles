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
            // case controls:
            //     mScreenState = mControlsScreen;
            //     break;
            // case skins:
            //     mScreenState = mSkinsScreen;
            //     break;
        }
    }
}

/**
 * @brief Update the screen based on the current screen state
 */
void Game::update() {
    switch(mScreenState) {
        case menu:
            mMenuScreen.update();
            break;
        case play:
            mScreenState = mPlayScreen.update();
            break;
        // case controls:
        //     mControlsScreen.update();
        //     break;
        // case skins:
        //     mSkinsScreen.update();
        //     break;
    }
}

/**
 * @brief Render based upon which screen is currently active (screen state)
 * 
 * @param window 
 */
void Game::render(sf::RenderWindow& window) {
    window.clear();
    switch (mScreenState) {
        case menu:
            mMenuScreen.render(window);
            mMenuScreen.fadeInText();
            break;
        case play:
            mPlayScreen.render(window);
            break;
        // case controls:
        //     mControlsScreen.render(window);
        //     break;
        // case skins:
        //     mSkinsScreen.render(window);
        //     break;
    }
    window.display();
}

