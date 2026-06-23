#pragma once
#include "ScreenBase.h"

class ControlMenu : public ScreenBase
{
 public:
  ControlMenu();
  ~ControlMenu();
  void init();
  void Update();
  int Input(const sf::Event::KeyPressed& key);
  void Render(sf::RenderWindow& game_window);

};
