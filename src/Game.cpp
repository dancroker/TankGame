#include "Game.h"

Game::Game()
{
  //1-8 player assets
} 

Game::~Game()
{
}

void Game::render(sf::RenderWindow& window) 
{
  map.drawMap(window);
  enemy.draw(window);
  player.draw(window);
  
}

void Game::update(float dt, sf::RenderWindow& window)
{
  sf::Vector2f prev_pos = player.getTank().getBodySprite().getPosition();
  float prev_rot        = player.getTank().getTankRotation();
  player.rotate(movement_x, dt);
  player.update(dt, window, static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)));
  enemy.update(dt, window, player.getTank().getBodySprite().getPosition());
  
  int collision = map.isTankColliding(player.getTank().getTankMarkers());

  if (enemy.getTank().bulletCollision(enemy.getTank().getTankMarkers(), player.getBulletLocation()))
  {
    std::cout << "HIT!!!!";
    enemy.getTank().death();
    player.bulletRemove();
  }

  sf::Vector2i true_movement = movement_y;
  if (collision != -1)
  {
    player.getTank().setTankRotation(prev_rot);
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
    player.getTank().setPos(prev_pos);

  }
  player.tankControl(true_movement, dt);
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
    player.fireGun();
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
