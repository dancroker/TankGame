#include "Game.h"

Game::Game()
{
  tank.setupTank(
    "assets/Ace Of Tanks Assets/Player/Player_5_body_1.png",
    "assets/Ace Of Tanks Assets/Player/Player_5_body_2.png",
    "assets/Ace Of Tanks Assets/Player/player_5_turret.png");
  tank.setPos({ 200, 200 });
  tankt.setupTank(
    "assets/Ace Of Tanks Assets/Enemies/enemy_4_body_1.png",
    "assets/Ace Of Tanks Assets/Enemies/enemy_4_body_2.png",
    "assets/Ace Of Tanks Assets/Enemies/enemy_4_turret.png");
  tankt.setPos({ 400, 400 });
  //1-8 player assets
} 

Game::~Game()
{
}

void Game::render(sf::RenderWindow& window) 
{
  map.drawMap(window);
  tankt.drawTank(window);
  tank.drawTank(window);
  
}

void Game::update(float dt, sf::RenderWindow& window)
{
  sf::Vector2f prev_pos = tank.getBodySprite().getPosition();
  float prev_rot        = tank.getTankRotation();
  tank.rotateTank(movement_x, dt);
  tank.updateTank(dt, window, static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)));
  tankt.updateTank(dt, window, tank.getBodySprite().getPosition());
  int collision = map.isTankColliding(tank.getTankMarkers());

  if (tankt.bulletCollision(tankt.getTankMarkers(), tank.getBullets().getLocation()))
  {
    std::cout << "HIT!!!!";
    tankt.death();
    tank.getBullets().remove();
  }

  sf::Vector2i true_movement = movement_y;
  if (collision != -1)
  {
    tank.setTankRotation(prev_rot);
    switch (collision+1)
    {
      case 1:
      case 2:
        true_movement.y = 0;
        break;
      case 3:
      case 4:
        true_movement.x = 0;
        break;
    
    }
    tank.setPos(prev_pos);
    
  }
  tank.tankControl(true_movement, dt);
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
