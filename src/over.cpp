/**
 * @file over.cpp
 * @author Isaiah Preston
 * @brief 
 * @date 2026-05-03
 */

#include "../hdr/over.hpp"

Over::Over() {
    if(!mFont.loadFromFile("ast/SPACE.ttf")) {
        std::cerr << "Error loading font file" << std::endl;
        exit(0);
    }

    if(!mBackgroundTexture.loadFromFile("ast/spacebackgroundbigger.png")) {
        std::cerr << "Error loading background file" << std::endl;
        exit(0);
    }

    mBackground.setTexture(mBackgroundTexture);

    mGameOver.setFont(mFont);
    mGameOver.setString("Game Over");
    mGameOver.setCharacterSize(80);
    mGameOver.setOrigin(mGameOver.getGlobalBounds().width/2, mGameOver.getGlobalBounds().height/2);
    mGameOver.setPosition({640, 50});


    // mDiedBy.setFont(mFont);
    // mYourScore.setFont(mFont);
    // mHighScore.setFont(mFont);

    // mTitle.setPosition({640,50});
    // mTitle.setFillColor(sf::Color::White);

    mMenu.setText("Menu");
    mMenu.setPosition({635, 600});
    mMenu.setSize({240, 100});
    mMenu.setColorTextNormal(sf::Color::White);
    mMenu.setTextSize(49);
    mMenu.setTextPosition({705,600});
}

screenState Over::handleInput(sf::Event& event, sf::RenderWindow& window) {
    if (mMenu.handleInput(event, window) || 
        (event.type == sf::Event::KeyPressed &&
        event.key.code == sf::Keyboard::Space)){
        mMenu.setButtonState(normal);
        return menu;
    }

    return over;
}

void Over::update() {
    mMenu.update();
}

void Over::render(sf::RenderWindow& window) {
    window.draw(mBackground);
    window.draw(mMenu);
    window.draw(mGameOver);
}