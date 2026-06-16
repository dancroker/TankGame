#pragma once
#include "Objects/Vehicles/Tank.h"
#include "Maps/Map.h"
class Game
{
 public:
  Game();
  ~Game();

  void render(sf::RenderWindow& window);
  void update(float dt, sf::RenderWindow& window);
  void keyPressed(const sf::Event::KeyPressed& key);
  void keyReleased(const sf::Event::KeyReleased& key);

 private:
  Tank tank;
  Map map;
  Tank tankt;
  sf::Vector2i movement_y = { 0, 0 };
  sf::Vector2i movement_x = { 0, 0 };
};
