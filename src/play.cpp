/**
 * @file play.cpp
 * @author Isaiah
 * @brief 
 * @date 2026-04-04
 */

#include "../hdr/play.hpp"

Play::Play() {
    for(int i = 0; i < 5; i++)
        mRow[i].setRow(i);

    if (!mBackgroundTexture.loadFromFile("assets/space.jpg")) { 
        std::cout<<"Error opening file\n";
        exit(1);
    }
    mBackground.setTexture(mBackgroundTexture);
}

screenState Play::handleInput(sf::Event& event, sf::RenderWindow& window) {
    mCharacter.handleInput(event, window);
    if(mRow[mCharacter.getRow()].getObs().checkIfInCharColumn())
        return menu;
    else 
        return play;
}

void Play::update() {
    mCharacter.update();
    for(int i = 0; i < 5; i++) {
        mRow[i].update();
    }
}

void Play::render(sf::RenderWindow& window) {
    window.draw(mCharacter);
    for(int i = 0; i < 5; i++) 
        mRow[i].getObs().render(window);
}
