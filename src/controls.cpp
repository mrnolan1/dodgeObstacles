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

//this will be for the play class(its own seperate functions for handling inputs, rendering, and updating screen for the how to play screen)
Controls::Controls() {

    //initialize variables and load resources here
    if (!mFont.loadFromFile("assets/SPACE.ttf"))
    {
        std::cout<<"Error opening file\n";
        exit(2);
    }
    if (!mBackgroundTexture.loadFromFile("assets/space.jpg"))
    {
        std::cout<<"Error opening background file\n";
        exit(2);
    }
    mBackground.setTexture(mBackgroundTexture);

    mSecondBackground.setTexture(mBackgroundTexture);
    mBackground.setPosition({0,0});
    mSecondBackground.setPosition({-800, 0});


    mTitle.setFont(mFont);
    //choose the font size based on button size
    mTitle.setCharacterSize(60);
    //set label
    mTitle.setString("    How to Play\n");
    mTitle.setOrigin(mTitle.getGlobalBounds().width/2, mTitle.getGlobalBounds().height/2);
    mTitle.setPosition({350,125});

    
    mInstructions.setFont(mFont);
    mInstructions.setCharacterSize(15);
    mInstructions.setString("       Objective: Avoid Asteroids, Spaceships and UFO's\n");
    mInstructions.setPosition({50, 250});

    mInstructions2.setString("          How to move Character:\n              Press w to move up \n            press s to move down, \n Press space bar to start the game.\n");
    mInstructions2.setFont(mFont);
    mInstructions2.setCharacterSize(15);
    mInstructions2.setPosition({170, 280});
    

    
    mMenu.setText("Menu");
    mMenu.setPosition({405, 450});
    mMenu.setSize({240, 100});
    mMenu.setColorTextNormal(sf::Color::White);
    mMenu.setTextPosition({475,450});


}

screenState Controls::handleInput(sf::Event& event, sf::RenderWindow& window)
{
    if (mMenu.handleInput(event, window)){
        return menu;
    }

    return controls;
}


void Controls::update() {
    //update the how to play screen here
    mMenu.update();
}

void Controls::moveBackground()
{
    if(mBackground.getPosition().x > 800)
    {
        mBackground.setPosition({-800,0});
        mBackgroundCounter = -800;
    }
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

void Controls::render(sf::RenderWindow& window) {
    window.draw(mBackground);
    window.draw(mSecondBackground);
    window.draw(mTitle);
    window.draw(mMenu);
    window.draw(mInstructions);
    window.draw(mInstructions2);
}

