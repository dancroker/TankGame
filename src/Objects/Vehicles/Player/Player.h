#pragma once
#include "../Tank.h"
#include "../../Projectiles/Bullet.h"
class Player
{
 public:
  Player();
  ~Player();
  void movePlayer(sf::Vector2i movement_y, sf::Vector2i movement_x, float dt);	
  void rotate(sf::Vector2i movement_x, float dt);
  void tankControl(sf::Vector2i movement_y, float dt);
  Tank& getTank() { return player_tank; };
  void draw(sf::RenderWindow& window);
  void update(float dt, sf::RenderWindow& window, sf::Vector2f aim_location);
  void fireGun();
  sf::Vector2f getBulletLocation() { return bullet.getLocation(); };
  void bulletRemove() { bullet.remove(); };

 private:
  Tank player_tank;
  Bullet bullet;
};
