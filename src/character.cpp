/**
 * @file character.cpp
 * @author Isaiah Preston
 * @brief Create a character controlled by the player. 
 *          If the character and any obstacle ever overlaps, end the game.
 * @date 2026-04-02
 */

#include "../hdr/character.hpp"

/**
 * @brief Construct a new Character::Character object
 *          Load character texture, set size, set row to center
 */
Character::Character() {
    if (!mTexture.loadFromFile("png/testCharacter.png")) { //check if character image file can be opened
        std::cout<<"Error opening file\n";
        exit(1);
    }
    mCharacter.setTexture(mTexture); //set sprite to character image
    sf::Vector2u characterSize{100, 100}; //set size of character
    mRow = 2; //starting row is center of screen
}

/**
 * @brief Hand input, arrows to move up and down, adjust row value
 * 
 * @param event 
 * @param window 
 */
void Character::handleInput(sf::Event& event, sf::RenderWindow& window) {
    if (event.type == sf::Event::KeyPressed) {
        if (((event.key.code == sf::Keyboard::Down) || (event.key.code == sf::Keyboard::S)) && mRow < 4)
            mRow++;
        else if (((event.key.code == sf::Keyboard::Up) || (event.key.code == sf::Keyboard::W)) && mRow > 0)
            mRow--;
    }
}

/**
 * @brief Hand update (set position off of current row value)
 */
void Character::update() {
    mCharacter.setPosition(700, (100*mRow));
}

/**
 * @brief Draw override (drawable)
 * 
 * @param target 
 * @param states 
 */
void Character::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(mCharacter);
}

/**
 * @brief Return current row value of character
 * 
 * @return int 
 */
int Character::getRow() {
    return mRow;
}

/**
 * @brief Reposition character at center when a new game starts
 */
void Character::reset() {
    mRow = 2;
    mCharacter.setPosition(700, (100*mRow));
}

/**
 * @brief Set character skin, error if file doesn't exist
 * 
 * @param file 
 */
void Character::setSkin(std::string file) {
    if(mTexture.loadFromFile(file))
        std::cerr << "Error opening skin file" << std::endl;
}