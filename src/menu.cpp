/**
 * @file menu.hpp
 * @author Matthew Nolan
 * @brief Menu screen: display title, background, and buttons 
 *          to switch to other screens (play, controls, skins)
 * @date 2026-04-11
 */

#include "../hdr/menu.hpp"

/**
 * @brief Construct a new Menu::Menu object
 *          Check font and background exists, set them
 *          Create three buttons:
 *              Play
 *              Controls
 *              Skins
 */
Menu::Menu() {
    if (!mFont.loadFromFile("ast/SPACE.ttf")) {
        std::cout<<"Error opening file\n";
        exit(2);
    }
    mTitle.setFont(mFont);
    mTitle.setCharacterSize(110);
    mTitle.setString("Adrift");
    mTitle.setOrigin(mTitle.getGlobalBounds().width/2, mTitle.getGlobalBounds().height/2);
    mTitle.setPosition({640, 150});
    mTitle.setFillColor({0,0,0,0});
    
    if (!mBackgroundTexture.loadFromFile("ast/spacebackgroundbigger.png")) {
        std::cout<<"Error opening background file\n";
        exit(2);
    }
    mBackground.setTexture(mBackgroundTexture);
    mSecondBackground.setTexture(mBackgroundTexture);
    mBackground.setPosition({mBackgroundCounter,0});
    mSecondBackground.setPosition({mBackgroundCounter2, 0});
    mBackground.setScale(1.01, 1);
    mSecondBackground.setScale(1.01, 1);


    mPlay.setText("Play");
    mPlay.setPosition({640, 440});
    mPlay.setSize({400, 200});
    mPlay.setColorTextNormal(sf::Color::White);
    mPlay.setTextSize(85);
    mPlay.setTextPosition({640, 415});

    mControls.setText("Controls");
    mControls.setPosition({220, 440});
    mControls.setSize({400, 150});
    mControls.setColorTextNormal(sf::Color::White);
    mControls.setTextSize(45);
    mControls.setTextPosition({370,440});

    mSkins.setText("Skins");
    mSkins.setPosition({1060, 440});
    mSkins.setSize({400, 150});
    mSkins.setColorTextNormal(sf::Color::White);
    mSkins.setTextSize(65);
    mSkins.setTextPosition({1100,430});
}

/**
 * @brief Handle input (which button did the user click?)
 * 
 * @param event 
 * @param window 
 * @return State 
 */
screenState Menu::handleInput(sf::Event& event, sf::RenderWindow& window) {
    if (mPlay.handleInput(event, window) || 
        (event.type == sf::Event::KeyPressed &&
        event.key.code == sf::Keyboard::Space))
        return play;
    else if (mControls.handleInput(event, window))
        return controls;
    else if (mSkins.handleInput(event, window))
        return skins;
    else 
        return menu;
}

/**
 * @brief Update each button
 */
void Menu::update(double dt) {
    mPlay.update();
    mControls.update();
    mSkins.update();

    moveBackground(dt);
}

/**
 * @brief Move background (flying through space)
 */
void Menu::moveBackground(double dt) {
    if(mBackgroundCounter > 1280) {
        mBackgroundCounter = -1280.f;
    } else if(mBackgroundCounter2 > 1280) {
        mBackgroundCounter2 = -1280.f;
    }

    mBackgroundCounter += 400.f*static_cast<float>(dt);
    mBackgroundCounter2 += 400.f*static_cast<float>(dt);
    mBackground.setPosition({mBackgroundCounter, 0});
    mSecondBackground.setPosition({mBackgroundCounter2, 0});
}

/**
 * @brief Fade title in
 * 
 */
void Menu::fadeInText(double dt) {
    if (mColorCounter < 255.0) {
        mColorCounter += 350.0 * dt;

        if (mColorCounter > 255.0)
            mColorCounter = 255.0;

        uint8_t alpha = static_cast<uint8_t>(mColorCounter);
        mTitle.setFillColor({alpha, alpha, alpha, alpha});
    }
}

/**
 * @brief Render each button
 * 
 * @param window 
 */
void Menu::render(sf::RenderWindow& window) {

    
    window.draw(mBackground);
    window.draw(mSecondBackground);

    window.draw(mTitle);
    window.draw(mPlay);
    window.draw(mControls);
    window.draw(mSkins);
}
