/**
 * @file menu.hpp
 * @author Matthew Nolan
 * @brief Menu screen: display title, background, and buttons 
 *          to switch to other screens (play, controls, skins)
 * @date 2026-04-11
 */

#include "../hdr/menu.hpp"
#include <iomanip>

/**
 * @brief Construct a new Menu::Menu object
 *          Check font and background exists, set them
 *          Create three buttons:
 *              Play
 *              Controls
 *              Skins
 */
Menu::Menu() {
    //open the font file
    if (!mFont.loadFromFile("ast/SPACE.ttf")) {
        std::cout<<"Error opening file\n";
        exit(2);
    }
    //set the specifications for the title
    mTitle.setFont(mFont);
    mTitle.setCharacterSize(110);
    mTitle.setString("Adrift");
    mTitle.setOrigin(mTitle.getGlobalBounds().width/2, mTitle.getGlobalBounds().height/2);
    mTitle.setPosition({640, 175});
    //set the opacity to 0 so the text will fade in
    mTitle.setFillColor({0,0,0,0});
    
    //open the background file
    if (!mBackgroundTexture.loadFromFile("ast/spacebackgroundbigger.png")) {
        std::cout<<"Error opening background file\n";
        exit(2);
    }

    //set the specifications for the background and second background (2nd for looping purposes)
    mBackground.setTexture(mBackgroundTexture);
    mSecondBackground.setTexture(mBackgroundTexture);
    mBackground.setPosition({mBackgroundCounter,0});
    mSecondBackground.setPosition({mBackgroundCounter2, 0});
    mBackground.setScale(1.01, 1);
    mSecondBackground.setScale(1.01, 1);

    //set the specifications for the play button
    mPlay.setText("Play");
    mPlay.setPosition({640, 440});
    mPlay.setSize({400, 200});
    mPlay.setColorTextNormal(sf::Color::White);
    mPlay.setTextSize(85);
    mPlay.setTextPosition({640, 415});

    //set the specifications for the controls button
    mControls.setText("Controls");
    mControls.setPosition({220, 440});
    mControls.setSize({400, 150});
    mControls.setColorTextNormal(sf::Color::White);
    mControls.setTextSize(45);
    mControls.setTextPosition({370,440});

    //set the specifications for the skins button
    mSkins.setText("Skins");
    mSkins.setPosition({1060, 440});
    mSkins.setSize({400, 150});
    mSkins.setColorTextNormal(sf::Color::White);
    mSkins.setTextSize(65);
    mSkins.setTextPosition({1100,430});

    mHighscore.setFont(mFont);
}

/**
 * @brief Handle input (which button did the user click?)
 * 
 * @param event 
 * @param window 
 * @return State 
 */
screenState Menu::handleInput(sf::Event& event, sf::RenderWindow& window) {
    //if the play button is pressed
    if (mPlay.handleInput(event, window) || 
        (event.type == sf::Event::KeyPressed &&
        event.key.code == sf::Keyboard::Space))
    {
        //set the play button back to normal
        mPlay.setButtonState(normal);
        //switch the screen to the play screen
        return play;
    }
    //if the controls button is pressed 
    else if (mControls.handleInput(event, window))
    {
        //set the controls button back to normal
        mControls.setButtonState(normal);
        //switch the screen to the controls screen
        return controls;
    }
    //if the skins button is pressed 
    else if (mSkins.handleInput(event, window))
    {
        //set the skins button back to normal
        mSkins.setButtonState(normal);
        //switch the screen to the skins screen
        return skins;
    }
    //if no button is pressed
    else 
    {
        //stay on the menu
        return menu;
    }
}

/**
 * @brief Update each button
 */
void Menu::update(double dt) {
    mPlay.update();
    mControls.update();
    mSkins.update();

    moveBackground(dt);


    
    std::ifstream highscoreFile("ast/highscore.txt");
    highscoreFile.seekg(0);

    if (!highscoreFile) {
        std::ofstream create("ast/highscore.txt");
        create << "0";
        create.close();
    }

    std::string highscoreStr;
    std::getline(highscoreFile, highscoreStr);

    double highscoreDbl = 0;

    if (!highscoreStr.empty()) {
        highscoreDbl = std::stod(highscoreStr);
    }

    std::ostringstream highscoreSS;
    highscoreSS << "High Score " << std::setprecision(highscoreDbl < 1 ? 4 : 5) << highscoreDbl;

    mHighscore.setString(highscoreSS.str());
    mHighscore.setCharacterSize(25);
    mHighscore.setOrigin(
        mHighscore.getGlobalBounds().width / 2,
        mHighscore.getGlobalBounds().height / 2
    );
    mHighscore.setPosition({640, 75});
}

/**
 * @brief Move background (flying through space)
 */
void Menu::moveBackground(double dt) {
    //if the background counter is greater than 1280, set it back to -1280
    if(mBackgroundCounter > 1280) {
        mBackgroundCounter = -1280.f;
    } 
    //if the second background counter is greater than 1280, set it back to -1280
    else if(mBackgroundCounter2 > 1280) {
        mBackgroundCounter2 = -1280.f;
    }

    //now increment the background counters
    mBackgroundCounter += 400.f*static_cast<float>(dt);
    mBackgroundCounter2 += 400.f*static_cast<float>(dt);
    //set the position of both of the backgrounds based on their background counters
    mBackground.setPosition({mBackgroundCounter, 0});
    mSecondBackground.setPosition({mBackgroundCounter2, 0});
}

/**
 * @brief Fade title in
 * 
 */
void Menu::fadeInText(double dt) {
    //if the opacity is < 255 (full opacity)
    if (mColorCounter < 255.0) {
        //set it higher
        mColorCounter += 350.0 * dt;

        //cap mColorCounter to 255
        if (mColorCounter > 255.0)
            mColorCounter = 255.0;

        //now set the color to the mColorCounter
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
    window.draw(mHighscore);
}
