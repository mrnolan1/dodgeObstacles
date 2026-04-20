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
#include "../hdr/howtoplay.hpp"
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

//this will be for the play class(its own seperate functions for handling inputs, rendering, and updating screen for the how to play screen)
HowToPlay::HowToPlay() {

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
    mTitle.setPosition({400,125});

    mTitle.setFillColor({0,0,0,0});

    //mInstructions.setTextSize();//in progress
    mInstructions.setText("Objective: Avoid Asteroids, Spaceships and Blackholes\n");
    mInstructions.setText("How to move Character: Press left arrow key to move down.\n Press right arrow key to move up.\n");
    //mInstructions.setSize();//in progress

    mMenu.setText("Back to Menu");
    mMenu.setPosition({400, 400});
    mMenu.setSize({240, 100});
    mMenu.setColorTextNormal(sf::Color::White);
    mMenu.setTextPosition({465,400});


    // std::cout << "How to Play" << std::endl;
    // std::cout << "Use the left arrow key to move down and right arrow key to move up."<<std::endl;
    // std::cout << "Avoid the obstacles." << std::endl;

}

screenState HowToPlay::handleInput(sf::Event& event, sf::RenderWindow& window)
{
    if (mMenu.handleInput(event, window)){
        return menu;

    }

    return howtoplay;
}


void HowToPlay::update() {
    //update the how to play screen here
    mMenu.update();
}

void HowToPlay::moveBackground()
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

void HowToPlay::render(sf::RenderWindow& window) {
    window.draw(mBackground);
    window.draw(mSecondBackground);
    window.draw(mTitle);
    window.draw(mMenu);
}

