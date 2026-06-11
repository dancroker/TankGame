#include "Game.h"

Game::Game()
{
  tank.setupTank(
    "assets/Ace Of Tanks Assets/Player/Player_3_body_1.png",
    "assets/Ace Of Tanks Assets/Player/Player_3_body_2.png",
    "assets/Ace Of Tanks Assets/Player/player_3_turret.png");
  tank.setPos({ 200, 200 });
} 

Game::~Game()
{
}

void Game::render(sf::RenderWindow& window) 
{
  tank.drawTank(window);
}

void Game::update(float dt, sf::RenderWindow& window)
{
  tank.tankControl(movement_y,movement_x,dt);
  tank.updateTank(dt, window);
}

void Game::keyPressed(const sf::Event::KeyPressed& key)
{
  if (key.code == sf::Keyboard::Key::W)
  {
    movement_y.y = -1;
  }
  if (key.code == sf::Keyboard::Key::S)
  {
    movement_y.x = 1;
  }
  if (key.code == sf::Keyboard::Key::A)
  {
    movement_x.y = -1;
  }
  if (key.code == sf::Keyboard::Key::D)
  {
    movement_x.x = 1;
  }
  if (key.code == sf::Keyboard::Key::Space)
  {
    tank.fireGun();
  }
  if (key.code == sf::Keyboard::Key::Escape)
  {
    // Can't close the window from here unless you have access to it.
  }
}

void Game::keyReleased(const sf::Event::KeyReleased& key)
{
  if (key.code == sf::Keyboard::Key::W)
  {
    movement_y.y = 0;
  }
  if (key.code == sf::Keyboard::Key::S)
  {
    movement_y.x = 0;
  }
  if (key.code == sf::Keyboard::Key::A)
  {
    movement_x.y = 0;
  }
  if (key.code == sf::Keyboard::Key::D)
  {
    movement_x.x = 0;
  }
}
