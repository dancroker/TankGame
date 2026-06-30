#pragma once
#include "../GameObject.h"
class Bullet
{
 public:
  Bullet();
  ~Bullet();
  void setLocation(sf::Vector2i location);
  void fire(float tank_rotation, sf::Vector2f position);
  void move(float dt, sf::RenderWindow& window);
  sf::Vector2f getLocation(){return bullet_object.getSprite()->getPosition();};
  sf::Sprite getSprite();
  void remove();
  void hitWall(sf::RenderWindow& window, sf::Vector2f location);
  bool gethasFired() { return hasFired; };

  private:
  GameObject bullet_object;
   float speed = 200;
   bool hasFired = false;
   float x_fire_location = 0;
   float y_fire_location = 0;

};
