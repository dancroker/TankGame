#pragma once
#include "Objects/Vehicles/Tank.h"
#include "Objects/Vehicles/Player/Player.h"
#include "Objects/Vehicles/Enemy/EnemyBase.h"
#include "Maps/Map.h"
#include "Screens/MainMenu.h"
#include "Screens/ControlMenu.h"
class Game
{
 public:
  Game();
  ~Game();

  void render(sf::RenderWindow& window);
  void update(float dt, sf::RenderWindow& window);
  void keyPressed(const sf::Event::KeyPressed& key, sf::RenderWindow& window);
  void keyReleased(const sf::Event::KeyReleased& key);

  void updatePlaying(float dt, sf::RenderWindow& window);

 private:
  Player player;
  Map map;
  EnemyBase enemy;
  sf::Vector2i movement_y = { 0, 0 };
  sf::Vector2i movement_x = { 0, 0 };

  MainMenu main_menu;
  ControlMenu control_menu;
  enum GameState
  {
	MainMenu,
	Playing,
	Paused,
	GameOver,
	Controls
  };
  GameState game_state = MainMenu;
};
