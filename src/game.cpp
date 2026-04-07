#include "obstacle.hpp"
#include "game.hpp"
#include <vector>

// Game::Game() : mWindow(sf::VideoMode(800, 500), "SFML Game") {
//     // Load resources, initialize game state, etc.
//     mWindow.setFramerateLimit(60);

//     // Test obstacle (yellow square)
//     Obstacle obs1(150.0f, 300.0f);//higher up, and faster
//     // obs1.setColor(sf::Color::Yellow);
//     m_obstacles.push_back(obs1);

//     Obstacle obs2(400.0f, 120.0f);//lower, slower
//     // obs2.setColor(sf::Color::Cyan);
//     m_obstacles.push_back(obs2);
    
//     Obstacle obs3(420.0f, 220.0f);//middle, medium speed
//     // obs3.setColor(sf::Color::Magenta);
//     m_obstacles.push_back(obs3);
// }

// void Game::run() {
//     sf::Clock clock;
//     while (mWindow.isOpen()) {
//         float dt = clock.restart().asSeconds();

//         processEvents();
//         update(dt);
//         render();
//     }
// }

// void Game::processEvents() {
//     sf::Event event;
//     while (mWindow.pollEvent(event)) {
//         if (event.type == sf::Event::Closed) {
//             mWindow.close();
//         }
//     }
// }

// void Game::update(float dt) {
//     // Move player with arrow keys
//     if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
//         m_player.move(0.0f,-m_playerSpeed * dt);
//     }
//     if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
//         m_player.move(0.0f, m_playerSpeed * dt);
//     }

//     // Keep player within window the screen
//     if (m_player.getPosition().y < 0) {
//         m_player.setPosition(m_player.getPosition().x, 0.0f);
//     }
//     if (m_player.getPosition().y + m_player.getSize().y > 600) {
//         m_player.setPosition(m_player.getSize().x, 600 -m_player.getPosition().y);
//     }
//     //update all obstacles
//     for(auto& obstacle : m_obstacles) {
//         obstacle.update(dt);
//     }
// }
// void Game::render() {
//     mWindow.clear(sf::Color::Black);

//     mWindow.draw(m_player); //Draw the red player

//      //draw all obstacles
//     for(auto& obstacle : m_obstacles) {
//         obstacle.render(mWindow);
//     }

//     mWindow.display();
// }
