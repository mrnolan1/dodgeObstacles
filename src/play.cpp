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
    
    mAirText.setFont(mFont);
    mAirText.setCharacterSize(30);
    mAirText.setPosition({17, 50});
    uint8_t color = 255.0;
    mAirText.setFillColor({color, color, color, color});
    
    mScoreText.setFont(mFont);
    mScoreText.setCharacterSize(30);
    mScoreText.setPosition({17, 10});
    mScoreText.setFillColor({color, color, color, color});
    
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

    mAir -= dt;
    if(mBubble.checkIfInCharColumn(mCharacter.getRow()))
        mAir = 10;
    if(mAir < 0) 
        return menu;

    std::ostringstream mAirSS;
    mAirSS << "Air: " << std::fixed << std::setprecision(2) << mAir;
    std::string mAirStr = mAirSS.str();
    mAirText.setString(mAirStr);

    mScore += dt;

    std::ostringstream mScoreSS;
    mScoreSS << "Score: " << std::fixed << std::setprecision(2) << mScore;
    std::string mScoreStr = mScoreSS.str();
    mScoreText.setString(mScoreStr);

    if(mRow[mCharacter.getRow()].eachCheckIfInCharColumn()) {
        return menu;        
    } else 
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
    
    mBubble.render(window);

    for(int i = 0; i < 9; i++) 
        mRow[i].render(window);

    window.draw(mAirText);
    window.draw(mScoreText);
}

/**
 * @brief Call reset functions when a new game starts on character and all obstacles
 */
void Play::reset() {
    mAir = 10.0;
    mScore = 0.0;
    mCharacter.reset();
    mBubble.reset();
    for(int i = 0; i < 9; i++) 
        mRow[i].reset();
}