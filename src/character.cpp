/**
 * @file character.cpp
 * @author Isaiah Preston
 * @brief Function definitions for Character class
 *          match).
 * @date 2026-04-02
 */

#include "../hdr/character.hpp"

Character::Character() {
    if (!mTexture.loadFromFile("png/testCharacter.png")) { //check if character image file can be opened
        std::cout<<"Error opening file\n";
        exit(1);
    }
    mCharacter.setTexture(mTexture); //set sprite to character image
    sf::Vector2u characterSize{100, 100}; //set size of character
    mCharacter.setOrigin(50, 50); //set origin of character to center
    mRow = 2; //starting row is center of screen
    mCharacter.setPosition(750, (100*mRow+50)); //set position to given row in character column
}

void Character::moveDown() {
    if(mRow < 4) 
        mRow++;
    mCharacter.setPosition(750, (100*mRow+50));
}

void Character::moveUp() {
    if(mRow > 0)
        mRow--;
    mCharacter.setPosition(750, (100*mRow+50));
}

int Character::getRow() {
    return mRow;
}

void Character::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(mCharacter);  // or mSprite
}