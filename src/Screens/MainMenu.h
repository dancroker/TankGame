#pragma once
#include "ScreenBase.h"
#include "../Objects/GameObject.h"
class MainMenu : public ScreenBase
{
 public:
  MainMenu();
  ~MainMenu();
  void init();
  void Update();
  int Input(const sf::Event::KeyPressed& key);
  void Render(sf::RenderWindow& game_window);
  void drawBackground(sf::RenderWindow& game_window);

 private:
  int option_selected = 0;
  GameObject tileset;
  GameObject p_tank_body;
  GameObject p_tank_turret;
  GameObject p2_tank_body;
  GameObject p2_tank_turret;
  GameObject p3_tank_body;
  GameObject p3_tank_turret;
  GameObject p4_tank_body;
  GameObject p4_tank_turret;
  int background[19][19] = {
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 6, 5, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 6, 5, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 6, 5, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 6, 5, 0, 0, 0 },
    { 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 10, 6, 5, 0, 0, 0 },
    { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 12, 5, 0, 0, 0 },
    { 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 11, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27, 26, 26, 26, 26, 26 },
    { 7, 7, 7, 7, 7, 7, 13, 0, 0, 0, 0, 0, 0, 28, 25, 25,25,32, 31 },
    { 14, 9, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 28, 25, 25, 25, 25, 25 },
    { 15, 16, 0, 0, 0, 0, 13, 0, 0, 0, 0, 0, 0, 28, 25, 25, 25, 25, 25 },
    { 15, 16, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 28, 25, 25, 25, 25, 25 },
    { 17, 18, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 28, 25, 25, 25, 25, 25 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 28, 25,25, 25, 25, 31 },
    { 0, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0, 0, 0, 29, 30, 30, 30, 30, 30 },
    { 0, 0, 23, 21, 21, 20, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 24, 22, 22, 19, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
  };
};
