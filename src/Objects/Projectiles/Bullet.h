#pragma once
#include "../GameObject.h"
class Bullet
{
 public:
  Bullet();
  ~Bullet();
  void setLocation(sf::Vector2i location);
  void fire(float tank_rotation);
  void move(float dt);
  sf::Sprite getSprite();

  private:
  GameObject bullet_object;
   float speed = 200;
   bool hasFired = false;
   float x_fire_location = 0;
   float y_fire_location = 0;
};
