#pragma once
#include "../GameObject.h"
#include "../Projectiles/Bullet.h"
class Tank
{

 public:
  Tank();
  ~Tank();
  void setupTank(std::string filename_1, std::string filename_2, std::string filename_3);
  void drawTank(sf::RenderWindow& window);
  void tankControl(sf::Vector2i movement_y, sf::Vector2i movement_x, float dt);
  float lookAt(sf::Vector2f from, sf::Vector2f too);
  void moveTank(int direction,float dt);
  void updateTank(float dt, sf::RenderWindow& window);
  void setPos(sf::Vector2f loc);
  void fireGun();
  sf::Vector2f getMuzzlePosition();

 private:
  sf::Vector2f position = { 0, 0 };
  GameObject tank_body_1;
  GameObject tank_body_2;
  GameObject tank_turret;
  float scale = 2;
  float turret_rotation = 0;
  float tank_rotation   = 0;
  float tank_rotation_speed    = 110;
  float tank_speed      = 100;
  float turret_rotation_speed = 120;
  sf::Vector2f muzzle_offset   = { 8.f, 0.f };
  Bullet bullets;
};
