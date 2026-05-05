/**
 * @file howtoplay.cpp
 * @author Mathew & Justin
 * @brief 
 * @version 0.1
 * @date 2026-04-10
 * 
 * @copyright Copyright (c) 2026
 * 
 */
#include "../hdr/menu.hpp"
#include "../hdr/button.hpp"
#include "../hdr/controls.hpp"
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

/** 

 * @brief Construct a new Controls:: Controls object 

 *  

 * Initializes fonts, texts, background sprites, title, instructions,  

 * and the menu button. 

 */ 
Controls::Controls() {
    //load font
    //initialize variables and load resources here
    if (!mFont.loadFromFile("ast/SPACE.ttf"))
    {
        std::cout<<"Error opening file\n";
        exit(2);
    }
    //load background texture
    if (!mBackgroundTexture.loadFromFile("ast/spacebackgroundbigger.png"))
    {
        std::cout<<"Error opening background file\n";
        exit(2);
    }
    //setup background sprites for scrolling
    mBackground.setTexture(mBackgroundTexture);

    mSecondBackground.setTexture(mBackgroundTexture);
    mBackground.setPosition({0,0});
    mSecondBackground.setPosition({-800, 0});

    //Title
    mTitle.setFont(mFont);
    //choose the font size based on button size
    mTitle.setCharacterSize(60);
    //set label
    mTitle.setString("    How to Play\n");
    mTitle.setOrigin(mTitle.getGlobalBounds().width/2, mTitle.getGlobalBounds().height/2);
    mTitle.setPosition({600,125});

    //first instruction text
    mInstructions.setFont(mFont);
    mInstructions.setCharacterSize(25);
    mInstructions.setString("       Objective: Avoid Asteroids, Spaceships, and UFO's\n                 while collecting air bubbles to survive!");
    mInstructions.setPosition({30, 150});

    //second instruction text
    mInstructions2.setString("               How to move Character:\n     Press w or up-arrow key to move up\nPress s or down-arrow key to move down \n    Press space bar to start the game\n");
    mInstructions2.setFont(mFont);
    mInstructions2.setCharacterSize(30);
    mInstructions2.setPosition({140, 280});
    

    //Menu button
    mMenu.setText("Menu");
    mMenu.setPosition({635, 600});
    mMenu.setSize({240, 100});
    mMenu.setColorTextNormal(sf::Color::White);
    mMenu.setTextSize(49);
    mMenu.setTextPosition({705,600});


}

/** 

 * @brief handle input for the controls screen 

 *  

 * @param event  

 * @param window  

 * @return screenState  

 */ 
screenState Controls::handleInput(sf::Event& event, sf::RenderWindow& window)
{
    if (mMenu.handleInput(event, window)){
        mMenu.setButtonState(normal);
        return menu;
    }

    return controls;
}
/** 

 * @brief update the controls screen every frame 

 *  

 * updates button visuals and background scrolling 

 */ 
void Controls::update() {
    //update the how to play screen here
    mMenu.update();
}
/** 

 * @brief Move both the background sprites to create a scrolling effect 

 *  

 * creates a scrolling background affect 

 */ 
void Controls::moveBackground()
{   //first loop background
    if(mBackground.getPosition().x > 800)
    {
        mBackground.setPosition({-800,0});
        mBackgroundCounter = -800;
    }
    //second loop background
    else if(mSecondBackground.getPosition().x > 800)
    {
        mSecondBackground.setPosition({-800,0});
        mBackgroundCounter2 = -800;
    }
    mBackgroundCounter = mBackgroundCounter + 0.5;
    mBackgroundCounter2 = mBackgroundCounter2 + 0.5;
    mBackground.setPosition({mBackgroundCounter, 0});
    mSecondBackground.setPosition({mBackgroundCounter2, 0});
}

/** 

 * @brief Render the controls screen 

 *  

 * @param window  

 */ 
void Controls::render(sf::RenderWindow& window) {
    window.draw(mBackground);
    window.draw(mSecondBackground);
    window.draw(mTitle);
    window.draw(mMenu);
    window.draw(mInstructions);
    window.draw(mInstructions2);
}
