/**
 * @file play.cpp
 * @author Isaiah Preston
 * @brief Play screen class. 
 *          Create background, character, 
 *          and rows (to hold obstacles)
 * @date 2026-04-04
 */

#include "../hdr/play.hpp"

/**
 * @brief Construct a new Play::Play object
 *          For each row, initialize its row value
 *          Set background (error if not exist)
 */
Play::Play() {
    for(int i = 0; i < 9; i++)
        mRow[i].setRow(i);

    if (!mBackgroundTexture.loadFromFile("assets/spacebackgroundsmaller.png")) {
        std::cout<<"Error opening background file\n";
        exit(2);
    }

    mBackground.setTexture(mBackgroundTexture);
    mBackground.setOrigin({250, 125});
    mBackground.setPosition({400, 200});
    mBackground.setScale({2.5, 2.5});
}

void Play::setPlayerSkin(std::string file)
{
    mCharacter.setSkin(file);
}

/**
 * @brief Handle user input (character)
 * 
 * @param event 
 * @param window 
 */
void Play::handleInput(sf::Event& event, sf::RenderWindow& window) {
    mCharacter.handleInput(event, window);
}

/**
 * @brief Update the screen (character and each row)
 *          If character and any obstacle overlap, end game
 * 
 * @return screenState 
 */
screenState Play::update(double dt) {
    mCharacter.update();
    
    for(int i = 0; i < 9; i++)
        mRow[i].update(dt);
    
    if(mRow[mCharacter.getRow()].eachCheckIfInCharColumn()) {
        std::cout << "GAME OVER\n";
        return menu;
    }
    else 
        return play;
}

/**
 * @brief Render background, character, and all obstacles
 * 
 * @param window 
 */
void Play::render(sf::RenderWindow& window) {
    window.draw(mBackground);
    window.draw(mCharacter);
    for(int i = 0; i < 9; i++) 
        mRow[i].render(window);
}

/**
 * @brief Call reset functions when a new game starts on character and all obstacles
 */
void Play::reset() {
    mCharacter.reset();
    for(int i = 0; i < 9; i++) 
        mRow[i].reset();
}