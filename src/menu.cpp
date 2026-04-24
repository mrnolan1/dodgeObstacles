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
    mTitle.setCharacterSize(60);
    mTitle.setString("Adrift");
    mTitle.setOrigin(mTitle.getGlobalBounds().width/2, mTitle.getGlobalBounds().height/2);
    mTitle.setPosition({400,125});
    mTitle.setFillColor({0,0,0,0});
    
    if (!mBackgroundTexture.loadFromFile("ast/spacebackgroundsmaller.png")) {
        std::cout<<"Error opening background file\n";
        exit(2);
    }
    mBackground.setTexture(mBackgroundTexture);
    mSecondBackground.setTexture(mBackgroundTexture);
    mBackground.setPosition({mBackgroundCounter,0});
    mSecondBackground.setPosition({mBackgroundCounter2, 0});
    mBackground.setScale(1280.f/500.f, 720.f/250.f);
    mSecondBackground.setScale(1280.f/500.f, 720.f/250.f);

    mPlay.setText("Play");
    mPlay.setPosition({400, 400});
    mPlay.setSize({240, 100});
    mPlay.setColorTextNormal(sf::Color::White);
    mPlay.setTextPosition({465,400});

    mControls.setText("Controls");
    mControls.setPosition({150, 400});
    mControls.setSize({230, 71});
    mControls.setColorTextNormal(sf::Color::White);
    mControls.setTextSize(25);
    mControls.setTextPosition({380,415});

    mSkins.setText("Skins");
    mSkins.setPosition({650, 400});
    mSkins.setSize({230, 71});
    mSkins.setColorTextNormal(sf::Color::White);
    mSkins.setTextSize(25);
    mSkins.setTextPosition({780,415});
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
        mBackgroundCounter = -1280;
    } else if(mBackgroundCounter2 > 1280) {
        mBackgroundCounter2 = -1280;
    }

    mBackgroundCounter += 500*dt;
    mBackgroundCounter2 += 500*dt;
    mBackground.setPosition({mBackgroundCounter, 0});
    mSecondBackground.setPosition({mBackgroundCounter2, 0});
}

/**
 * @brief Fade title in
 * 
 */
void Menu::fadeInText(double dt) {
    if (mColorCounter < 255) {
        mColorCounter+=1000*dt;
        mTitle.setFillColor({mColorCounter, mColorCounter, mColorCounter, mColorCounter});
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
