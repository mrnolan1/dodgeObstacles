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
    if (!mFont.loadFromFile("ast/SPACE.ttf")) {
        std::cout<<"Error opening file\n";
        exit(2);
    }
    mTitle.setFont(mFont);
    mTitle.setCharacterSize(20);
    mTitle.setOrigin(mTitle.getGlobalBounds().width/2, mTitle.getGlobalBounds().height/2);
    mTitle.setPosition({640, 160});
    mTitle.setFillColor({0,0,0,0});
    
    for(int i = 0; i < 9; i++)
        mRow[i].setRow(i);

    if (!mBackgroundTexture.loadFromFile("ast/spacebackgroundbigger.png")) {
        std::cout<<"Error opening background file\n";
        exit(2);
    }

    mBackground.setTexture(mBackgroundTexture);
    mBackground.setPosition({0, 0});
}

/**
 * @brief set the skin of the character object
 * 
 * @param file 
 */
void Play::setPlayerSkin(std::string file) {
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
    mBubble.update(dt);

    // Update each row
    for(int i = 0; i < 9; i++)
        mRow[i].update(dt);

    oxygenUpdate(dt);
    if(mBubble.checkIfInCharColumn(mCharacter.getRow()))
        mOxygen = 10;
    if(mOxygen < 0)
        return menu;

    std::ostringstream ss;
    ss << std::fixed << std::setprecision(4) << mOxygen;
    mOxCnt = ss.str();
    mTitle.setString(mOxCnt);

    if(mRow[mCharacter.getRow()].eachCheckIfInCharColumn()) {
        return menu;        
    } else 
        return play;
}

void Play::oxygenUpdate(double dt) {
    mOxygen -= dt;
    std::cout << mOxygen << '\n';
}

/**
 * @brief Render background, character, and all obstacles
 * 
 * @param window 
 */
void Play::render(sf::RenderWindow& window) {
    window.draw(mBackground);
    window.draw(mCharacter);
    
    mBubble.render(window);

    for(int i = 0; i < 9; i++) 
        mRow[i].render(window);
}

/**
 * @brief Call reset functions when a new game starts on character and all obstacles
 */
void Play::reset() {
    mOxygen = 10;
    mCharacter.reset();
    mBubble.reset();
    for(int i = 0; i < 9; i++) 
        mRow[i].reset();
}