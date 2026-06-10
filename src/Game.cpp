#include "Game.h"

Game::Game()
{
  tank.setupTank(
    "../assets/Ace Of Tanks Assets/Player/Player_3_body_1.png",
    "../assets/Ace Of Tanks Assets/Player/Player_3_body_2.png",
    "../assets/Ace Of Tanks Assets/Player/Player_3_turret.png");
} 
Game::~Game()
{
}

void Game::render(sf::RenderWindow& window) 
{
  tank.drawTank(window);
}

void Game::keyPressed(const sf::Event::KeyPressed& key)
{
  if (key.code == sf::Keyboard::Key::W)
  {
    std::cout << "W pressed\n";
    tank.moveTank({ 0, -1 });
  }
  if (key.code == sf::Keyboard::Key::S)
  {
    std::cout << "W pressed\n";
    tank.moveTank({ 0, 1 });
  }
  if (key.code == sf::Keyboard::Key::A)
  {
    std::cout << "W pressed\n";
    tank.moveTank({ -1, 0 });
  }
  if (key.code == sf::Keyboard::Key::D)
  {
    std::cout << "W pressed\n";
    tank.moveTank({ 1, 0 });
  }

  if (key.code == sf::Keyboard::Key::Escape)
  {
    // Can't close the window from here unless you have access to it.
  }
}