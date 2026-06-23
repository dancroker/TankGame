#pragma once
#include "ScreenBase.h"
class MainMenu : public ScreenBase
{
 public:
  MainMenu();
  ~MainMenu();
  void init();
  void Update();
  int Input(const sf::Event::KeyPressed& key);
  void Render(sf::RenderWindow& game_window);

 private:
  int option_selected = 0;
};
