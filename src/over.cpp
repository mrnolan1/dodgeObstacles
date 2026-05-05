/**
 * @file over.cpp
 * @author Isaiah Preston
 * @brief 
 * @date 2026-05-03
 */

#include "../hdr/over.hpp"
#include <iomanip>

/**
 * @brief Construct a new Over:: Over object
 * 
 */
Over::Over() {
    if(!mBackgroundTexture.loadFromFile("ast/spacebackgroundbigger.png")) {
        std::cerr << "Error loading background file" << std::endl;
        exit(0);
    }
    mBackground.setTexture(mBackgroundTexture);

    if(!mFont.loadFromFile("ast/SPACE.ttf")) {
        std::cerr << "Error loading font file" << std::endl;
        exit(0);
    }

    mGameOver.setFont(mFont);
    mGameOver.setString("Game Over");
    mGameOver.setCharacterSize(90);
    mGameOver.setOrigin(mGameOver.getGlobalBounds().width/2, mGameOver.getGlobalBounds().height/2);
    mGameOver.setPosition({640, 90});

    mDiedBy.setFont(mFont);

    mYourScore.setFont(mFont);
    
    mHighscoreFile.open("ast/highscore.txt", std::ios::in | std::ios::out);
    mHighscore.setFont(mFont);

    mMenu.setText("Menu");
    mMenu.setPosition({635, 600});
    mMenu.setSize({240, 100});
    mMenu.setColorTextNormal(sf::Color::White);
    mMenu.setTextSize(49);
    mMenu.setTextPosition({705,600});
}

/**
 * @brief Handle user input: menu button goes to menu, space to play again
 * 
 * @param event 
 * @param window 
 * @return screenState 
 */
screenState Over::handleInput(sf::Event& event, sf::RenderWindow& window) {
    if (mMenu.handleInput(event, window)){
        mMenu.setButtonState(normal);
        return menu;
    } else if(event.type == sf::Event::KeyPressed &&
        event.key.code == sf::Keyboard::Space) {
        mMenu.setButtonState(normal);
        return overSkipMenu;
    } else {
        return over;
    }

}

/**
 * @brief Update the menu button
 * 
 */
void Over::update() {
    mMenu.update();
}

/**
 * @brief One time use to set the strings of you score, high score, etc
 * 
 * @param cod 
 * @param score 
 */
void Over::setScreen(causeOfDeath cod, double score) {
    std::string diedByStr;
    switch(cod) {
        case suffocation:
            diedByStr = "Died to Suffocation";
            break;
        case asteroid:
            diedByStr = "Died to Asteroid";
            break;  
        case spaceship:
            diedByStr = "Died to Spaceship";
            break;
        case ufo:
            diedByStr = "Died to UFO";
            break;        
    }
    mDiedBy.setString(diedByStr);
    mDiedBy.setCharacterSize(40);
    mDiedBy.setOrigin(mDiedBy.getGlobalBounds().width/2, mDiedBy.getGlobalBounds().height/2);
    mDiedBy.setPosition({640, 230});

    std::ostringstream yourscoreSS;
    yourscoreSS << "Your Score " << std::setprecision(score < 1 ? 4 : 5) << score;
    std::string yourscoreStr = yourscoreSS.str();
    mYourScore.setString(yourscoreStr);
    mYourScore.setCharacterSize(40);
    mYourScore.setOrigin(mYourScore.getGlobalBounds().width/2, mYourScore.getGlobalBounds().height/2);
    mYourScore.setPosition({640, 330});


    mHighscoreFile.clear();
    mHighscoreFile.seekg(0);

    std::string highscoreStr;
    std::getline(mHighscoreFile, highscoreStr);

    double highscoreDbl = 0;

    if (!highscoreStr.empty()) {
        highscoreDbl = std::stod(highscoreStr);
    }

    if (score > highscoreDbl) {
        highscoreDbl = score;

        std::ofstream highscoreOFS("ast/highscore.txt", std::ios::trunc);
        highscoreOFS << score;
        highscoreOFS.close();
    }

    std::ostringstream highscoreSS;
    highscoreSS << "High Score " << std::setprecision(highscoreDbl < 1 ? 4 : 5) << highscoreDbl;

    mHighscore.setString(highscoreSS.str());
    mHighscore.setCharacterSize(40);
    mHighscore.setOrigin(
        mHighscore.getGlobalBounds().width / 2,
        mHighscore.getGlobalBounds().height / 2
    );
    mHighscore.setPosition({640, 430});
}

/**
 * @brief Render the sprites to the window
 * 
 * @param window 
 */
void Over::render(sf::RenderWindow& window) {
    window.draw(mBackground);
    window.draw(mMenu);
    window.draw(mGameOver);
    window.draw(mDiedBy);
    window.draw(mYourScore);
    window.draw(mHighscore);
}