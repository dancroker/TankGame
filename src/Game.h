#pragma once
#include "Objects/Vehicles/Tank.h"
class Game
{
 public:
  Game();
  ~Game();

  void render(sf::RenderWindow& window);
  void keyPressed(const sf::Event::KeyPressed& key);

  private:
    Tank tank;
};
