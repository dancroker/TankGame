#pragma once
#include "../GameObject.h"
class Tank
{

 public:
  Tank();
  ~Tank();
  void setupTank(std::string filename_1, std::string filename_2, std::string filename_3);
  void drawTank(sf::RenderWindow& window);
  void moveTank(sf::Vector2i movement);

 private:
  sf::Vector2f position = { 0, 0 };
  GameObject tank_body_1;
  GameObject tank_body_2;
  GameObject tank_turret;
};
