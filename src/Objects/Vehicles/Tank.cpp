#include "Tank.h"

Tank::Tank() {}
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
}

void Tank::drawTank(sf::RenderWindow& window)
{
  if (is_alive)
  {
    // Draw body 1 and marker attached to it
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
      tank_turret.setPosition(position.x, position.y);
      tank_turret.getSprite()->setRotation(sf::degrees(turret_rotation));
      window.draw(*tank_turret.getSprite());
    }
    drawTankMarkers(window);
  }
}

float Tank::lookAt(sf::Vector2f from, sf::Vector2f to)
{
  sf::Vector2f direction = to - from;

  return std::atan2(direction.y, direction.x) * 180.f / 3.14159265358979323846f;
}

float dot(sf::Vector2f a, sf::Vector2f b)
{
  return a.x * b.x + a.y * b.y;
}

bool Tank::bulletCollision(sf::Vector2f tank_coords[4], sf::Vector2f bullet_coords) 
{
  if (is_alive)
  {
    // COMMENT how this works!!!
    sf::Vector2f AB = tank_coords[1] - tank_coords[0];
    sf::Vector2f AD = tank_coords[3] - tank_coords[0];
    sf::Vector2f AP = bullet_coords - tank_coords[0];

    float dotAB = dot(AP, AB);
    float dotAD = dot(AP, AD);

    float lenAB = dot(AB, AB);
    float lenAD = dot(AD, AD);

    bool inside = dotAB >= 0 && dotAB <= lenAB && dotAD >= 0 && dotAD <= lenAD;
    return inside;
  }
  return false;
}

void Tank::moveTank(int direction, float dt) 
{
  float x = cos((tank_rotation-90.f) * 3.14159265358979323846f / 180.f);
  float y = sin((tank_rotation-90.f) * 3.14159265358979323846f / 180.f);

  tank_body_1.getSprite()->move({ ((x * tank_speed)*direction)*dt, ((y * tank_speed)*direction)*dt });
  position = tank_body_1.getSprite()->getPosition();
}

void Tank::updateTank(float dt, sf::RenderWindow& window,sf::Vector2f aim_location)
{
  if (is_alive)
  {
    float desired_angle =
      lookAt(tank_turret.getSprite()->getPosition(), aim_location) + 90;
    float turn_amount_left =
      std::remainder(turret_rotation - desired_angle, 360);

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
      turret_rotation += (turret_rotation_speed * dt);
    }
    else
    {
      turret_rotation -= (turret_rotation_speed * dt);
    }
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

void Tank::death() 
{
  is_alive = false;
}

void Tank::drawTankMarkers(sf::RenderWindow& window)
{
  sf::Vector2f marker_local_offset = { 3.f, 2.f };
  static sf::Color marker_color = sf::Color(255, 0, 0, 200);
  
  // Marker Set Up
  sf::CircleShape marker(2.0f);
  marker.setOrigin({ 2, 2 });
  marker.setFillColor(marker_color);

  // Top Left
  {
    sf::Vector2f marker_local_offset = { 3.f, 2.f };
    sf::Sprite* bodySprite           = tank_body_1.getSprite();
    sf::Vector2f markerWorldPos =
      bodySprite->getTransform().transformPoint(marker_local_offset);
    marker.setPosition(markerWorldPos);
    window.draw(marker);
  }
  {
    // Top Right
    sf::Vector2f marker_local_offset = { 30.5f, 2.f };
    sf::Sprite* bodySprite           = tank_body_1.getSprite();
    sf::Vector2f markerWorldPos =
      bodySprite->getTransform().transformPoint(marker_local_offset);
    marker.setPosition(markerWorldPos);
    window.draw(marker);
  }
  {
    // Bottom Left
    sf::Vector2f marker_local_offset = { 3.f, 45.f };
    sf::Sprite* bodySprite           = tank_body_1.getSprite();
    sf::Vector2f markerWorldPos =
      bodySprite->getTransform().transformPoint(marker_local_offset);
    marker.setPosition(markerWorldPos);
    window.draw(marker);
  }
  {
    // Bottom Right
    sf::Vector2f marker_local_offset = { 30.5f, 45.f };
    sf::Sprite* bodySprite           = tank_body_1.getSprite();
    sf::Vector2f markerWorldPos =
      bodySprite->getTransform().transformPoint(marker_local_offset);
    marker.setPosition(markerWorldPos);
    window.draw(marker);
  }
}

sf::Vector2f* Tank::getTankMarkers()
{
  static sf::Vector2f tank_markers[4];
  tank_markers[0] = tank_body_1.getSprite()->getTransform().transformPoint({ 3.f, 2.f });
  tank_markers[1] = tank_body_1.getSprite()->getTransform().transformPoint({ 30.5f, 2.f });
  tank_markers[2] = tank_body_1.getSprite()->getTransform().transformPoint({ 3.f, 45.f });
  tank_markers[3] = tank_body_1.getSprite()->getTransform().transformPoint({ 30.5f, 45.f });
  return tank_markers;
}

void Tank::rotateTank(sf::Vector2i movement_x, float dt)
{
  if (movement_x.x != 0)
  {
    setTankRotation(
      getTankRotation() + getTankRotationSpeed() * dt);
  }
  if (movement_x.y != 0)
  {
    setTankRotation(
      getTankRotation() -   getTankRotationSpeed() * dt);
  }
  getBodySprite().setRotation(sf::degrees(getTankRotation()));
}

