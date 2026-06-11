#include "Tank.h"

Tank::Tank() 
{

}
Tank::~Tank() {}

void Tank::setupTank(std::string filename_1, std::string filename_2, std::string filename_3)
{
  tank_body_1.initialiseSprite(filename_1);
  tank_body_1.getSprite()->setScale({ scale, scale });
  float point = tank_body_1.getSprite()->getGlobalBounds().size.y / 4;
  tank_body_1.getSprite()->setOrigin({tank_body_1.getSprite()->getGlobalBounds().size.x / 4, point});

  tank_body_2.initialiseSprite(filename_2);
  tank_body_2.getSprite()->setScale({ scale, scale });
  tank_body_2.setVisible(false);
  tank_turret.initialiseSprite(filename_3);

  point = tank_turret.getSprite()->getGlobalBounds().size.y/1.5;
  tank_turret.getSprite()->setOrigin(
    { tank_turret.getSprite()->getGlobalBounds().size.x/2, point});
  tank_turret.getSprite()->setScale({ scale, scale });


  //-------------------------------------------
}

void Tank::drawTank(sf::RenderWindow& window) 
{
  window.draw(bullets.getSprite());
  if (tank_body_1.getVisible())
  {
    tank_body_1.getSprite()->setRotation(sf::degrees(tank_rotation));
    window.draw(*tank_body_1.getSprite());
    position = tank_body_1.getSprite()->getPosition();

    
  }
  if (tank_body_2.getVisible())
  {
    window.draw(*tank_body_2.getSprite());
  }
  if (tank_turret.getVisible())
  {
    tank_turret.setPosition(
      position.x ,
      position.y );
    tank_turret.getSprite()->setRotation(sf::degrees(turret_rotation));
    window.draw(*tank_turret.getSprite());

  }
}

void Tank::tankControl(sf::Vector2i movement_y, sf::Vector2i movement_x,float dt)
{
  if (movement_x.x != 0)
  {
    tank_rotation += tank_rotation_speed * dt;
  }
  if (movement_x.y != 0)
  {
    tank_rotation -= tank_rotation_speed * dt;
  }
  if (movement_y.y != 0)
  {
    moveTank(1,dt);
  }
  if (movement_y.x != 0)
  {
    moveTank(-1,dt);
  }
}

float Tank::lookAt(sf::Vector2f from, sf::Vector2f to)
{
  sf::Vector2f direction = to - from;

  return std::atan2(direction.y, direction.x) * 180.f / 3.14159265358979323846f;
}

void Tank::moveTank(int direction, float dt) 
{
  float x = cos((tank_rotation-90.f) * 3.14159265358979323846f / 180.f);
  float y = sin((tank_rotation-90.f) * 3.14159265358979323846f / 180.f);

  tank_body_1.getSprite()->move({ ((x * tank_speed)*direction)*dt, ((y * tank_speed)*direction)*dt });
  position = tank_body_1.getSprite()->getPosition();
}

void Tank::updateTank(float dt, sf::RenderWindow& window)
{
  bullets.move(dt);
  sf::Vector2f mouse_location =
    static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));
  float desired_angle =
    lookAt(tank_turret.getSprite()->getPosition(), mouse_location) + 90;
  float turn_amount_left = std::remainder(turret_rotation - desired_angle, 360);

  if (turn_amount_left > 180)
  {
    turn_amount_left = turn_amount_left - 360;
  }
  if (turn_amount_left < -180)
  {
    turn_amount_left = turn_amount_left + 360;
  }

  if (turn_amount_left < 0)
  {
    turret_rotation += turret_rotation_speed*dt;
  }
  else
  {
    turret_rotation -= turret_rotation_speed*dt;
  }

}

void Tank::setPos(sf::Vector2f loc) 
{
  tank_body_1.setPosition(loc.x, loc.y);
}

sf::Vector2f Tank::getMuzzlePosition()
{
  return tank_turret.getSprite()->getTransform().transformPoint(muzzle_offset);
}

void Tank::fireGun() 
{
  bullets.setLocation(static_cast<sf::Vector2i>(getMuzzlePosition()));
  bullets.fire(turret_rotation);

}


