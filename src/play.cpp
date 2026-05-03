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
    
    uint8_t color = 255.0;

    mAirStr.setFont(mFont);
    mAirStr.setCharacterSize(30);
    mAirStr.setPosition({17, 50});
    mAirStr.setFillColor({color, color, color, color});
    mAirStr.setString("Air ");
    
    mAirBar.setPosition({108.f, 64.f});  
 
    mAirFrame.setFillColor({color, color, color, 0}); 
    mAirFrame.setPosition({105.f, 61.f});  
    mAirFrame.setSize(sf::Vector2f(170.f, 15.f));
    mAirFrame.setOutlineThickness(3.f);
    mAirFrame.setOutlineColor({color, color, color, color});

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
        mAir = 9.0;

    double airLvl = (mAir/9)*164.0;
    mAirBar.setSize(sf::Vector2f(airLvl, 9.f));
    mAirBar.setFillColor(mAir < 3.0 ? sf::Color::Red : sf::Color::White);

    mScore += dt;

    std::ostringstream mScoreSS;
    mScoreSS << "Score " << std::setprecision(mScore < 1 ? 4 : 5) << mScore;
    std::string mScoreStr = mScoreSS.str();
    mScoreText.setString(mScoreStr);

    if(mAir < 0) 
        return over;
    if(mRow[mCharacter.getRow()].eachCheckIfInCharColumn()) {
        return over;        
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

    window.draw(mAirStr);
    
    window.draw(mAirFrame);
    window.draw(mAirBar);
    window.draw(mScoreText);
}

/**
 * @brief Call reset functions when a new game starts on character and all obstacles
 */
void Play::reset() {
    mAir = 9.0;
    mScore = 0.0;
    mCharacter.reset();
    mBubble.reset();
    for(int i = 0; i < 9; i++) 
        mRow[i].reset();
}