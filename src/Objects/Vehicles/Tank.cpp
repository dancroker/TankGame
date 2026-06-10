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
  //tank_turret.setVisible(false);
}

void Tank::drawTank(sf::RenderWindow& window) 
{
  if (tank_body_1.getVisible())
  {
    tank_body_1.setPosition(position.x, position.y);
    tank_body_1.getSprite()->setRotation(sf::degrees(tank_rotation));
    window.draw(*tank_body_1.getSprite());

    tank_rotation -= 0.01;

    {
      sf::Sprite* bodySprite     = tank_body_1.getSprite();
      sf::Vector2f bodyOriginPos = bodySprite->getPosition();
      const float bodyDotRadius  = 3.0f;
      sf::CircleShape bodyDot(bodyDotRadius);
      bodyDot.setFillColor(sf::Color::Blue);
      bodyDot.setOrigin({ bodyDotRadius, bodyDotRadius }); // center the circle
                                                           // on the origin
                                                           // point
      bodyDot.setPosition(bodyOriginPos);
      window.draw(bodyDot);
    }
  }
  if (tank_body_2.getVisible())
  {
    tank_body_2.setPosition(position.x, position.y);
    window.draw(*tank_body_2.getSprite());
  }
  if (tank_turret.getVisible())
  {
    tank_turret.setPosition(
      position.x ,
      position.y );
    tank_turret.getSprite()->setRotation(sf::degrees(turret_rotation));
    
    turret_rotation += 0.01;
    
    window.draw(*tank_turret.getSprite());

    {
      sf::Sprite* turretSprite    = tank_turret.getSprite();
      sf::Vector2f originWorldPos = turretSprite->getPosition();
      const float dotRadius       = 3.0f;
      sf::CircleShape dot(dotRadius);
      dot.setFillColor(sf::Color::Red);
      dot.setOrigin({ dotRadius, dotRadius }); // center the circle on the
                                               // origin point
      dot.setPosition(originWorldPos);
      window.draw(dot);
    }
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
