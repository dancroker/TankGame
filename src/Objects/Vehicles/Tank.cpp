#include "Tank.h"

Tank::Tank() 
{

}
Tank::~Tank() {}

void Tank::setupTank(std::string filename_1, std::string filename_2, std::string filename_3)
{
  tank_body_1.initialiseSprite(filename_1);
  tank_body_2.initialiseSprite(filename_2);
  tank_body_2.setVisible(false);
  tank_turret.initialiseSprite(filename_3);
}

void Tank::drawTank(sf::RenderWindow& window) 
{
  if (tank_body_1.getVisible())
  {
    tank_body_1.setPosition(position.x, position.y);
    window.draw(*tank_body_1.getSprite());
  }
  if (tank_body_2.getVisible())
  {
    tank_body_2.setPosition(position.x, position.y);
    window.draw(*tank_body_2.getSprite());
  }
  if (tank_turret.getVisible())
  {
    tank_turret.setPosition(position.x, position.y);
    window.draw(*tank_turret.getSprite());
  }
}

void Tank::moveTank(sf::Vector2i movement) 
{
  if (movement.x > 0)
  {
    position.x += 10;
  }
  else if (movement.x < 0)
  {
    position.x -= 10;
  }
  if (movement.y > 0)
  {
    position.y += 10;
  }
  else if (movement.y < 0)
  {
    position.y -= 10;
  }
}
