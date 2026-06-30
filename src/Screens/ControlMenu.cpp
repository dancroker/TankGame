#include "ControlMenu.h"
ControlMenu::ControlMenu() 
{
  init();
}

ControlMenu::~ControlMenu() {}

void ControlMenu::init() 
{
  p_tank_body.initialiseSprite("assets/Ace Of Tanks Assets/Player/Player_3_body_1.png");
  p_tank_body.setPosition(700, 300);
  p_tank_body.getSprite()->setScale({ 3.0, 3.0 });
  p_tank_turret.initialiseSprite("assets/Ace Of Tanks Assets/Player/Player_3_turret.png");
  p_tank_turret.setPosition(670, 450);
  p_tank_turret.getSprite()->setScale({ 3.0, 3.0 });
  p_tank_turret.getSprite()->setRotation(sf::degrees(245));

  e_tank_body_1.initialiseSprite("assets/Ace Of Tanks Assets/Enemies/enemy_4_body_1.png");
  e_tank_body_1.setPosition(150, 500);
  e_tank_body_1.getSprite()->setScale({ 3.0, 3.0 });
  e_tank_body_1.getSprite()->setRotation(sf::degrees(50));
  e_tank_turret_1.initialiseSprite("assets/Ace Of Tanks Assets/Enemies/enemy_4_turret.png");
  e_tank_turret_1.setPosition(120, 500);
  e_tank_turret_1.getSprite()->setScale({ 3.0, 3.0 });
  e_tank_turret_1.getSprite()->setRotation(sf::degrees(20));

  tileset.initialiseSprite("assets/Ace Of Tanks Assets/tileset.png");
  tileset.setPosition(0, 0);
  tileset.getSprite()->setScale({ 3, 3 });
}

void ControlMenu::Update() 
{
}

int ControlMenu::Input(const sf::Event::KeyPressed& key) 
{
  if (key.code == sf::Keyboard::Key::Escape)
  {
	return 0;
  }
  return -1;
}

void ControlMenu::Render(sf::RenderWindow& game_window) 
{

  for (int x = 0; x < 19; x++)
  {
    for (int y = 0; y < 19; y++)
    {
      switch (background[y][x])
      {
        case 0:
        {
          int tile_x = 20;
          int tile_y = 39;
          tileset.getSprite()->setTextureRect(
            sf::IntRect({ 16 * tile_x, 16 * tile_y }, { 16, 16 }));
          break;
        }
        case 1:
        {
          int tile_x = 2;
          int tile_y = 2;
          tileset.getSprite()->setTextureRect(
            sf::IntRect({ 16 * tile_x, 16 * tile_y }, { 16, 16 }));
          break;
        }
        case 2:
        {
          int tile_x = 2;
          int tile_y = 1;
          tileset.getSprite()->setTextureRect(
            sf::IntRect({ 16 * tile_x, 16 * tile_y }, { 16, 16 }));
          break;
        }
        case 3:
        {
          int tile_x = 1;
          int tile_y = 2;
          tileset.getSprite()->setTextureRect(
            sf::IntRect({ 16 * tile_x, 16 * tile_y }, { 16, 16 }));
          break;
        }
        case 4:
        {
          int tile_x = 2;
          int tile_y = 3;
          tileset.getSprite()->setTextureRect(
            sf::IntRect({ 16 * tile_x, 16 * tile_y }, { 16, 16 }));
          break;
        }
        case 5:
        {
          int tile_x = 3;
          int tile_y = 2;
          tileset.getSprite()->setTextureRect(
            sf::IntRect({ 16 * tile_x, 16 * tile_y }, { 16, 16 }));
          break;
        }
        case 6:
        {
          int tile_x = 1;
          int tile_y = 1;
          tileset.getSprite()->setTextureRect(
            sf::IntRect({ 16 * tile_x, 16 * tile_y }, { 16, 16 }));
          break;
        }
        case 7:
        {
          int tile_x = 3;
          int tile_y = 1;
          tileset.getSprite()->setTextureRect(
            sf::IntRect({ 16 * tile_x, 16 * tile_y }, { 16, 16 }));
          break;
        }
        case 8:
        {
          int tile_x = 1;
          int tile_y = 3;
          tileset.getSprite()->setTextureRect(
            sf::IntRect({ 16 * tile_x, 16 * tile_y }, { 16, 16 }));
          break;
        }
        case 9:
        {
          int tile_x = 3;
          int tile_y = 3;
          tileset.getSprite()->setTextureRect(
            sf::IntRect({ 16 * tile_x, 16 * tile_y }, { 16, 16 }));
          break;
        }
        case 10:
        {
          int tile_x = 2;
          int tile_y = 6;
          tileset.getSprite()->setTextureRect(
            sf::IntRect({ 16 * tile_x, 16 * tile_y }, { 16, 16 }));
          break;
        }
        case 11:
        {
          int tile_x = 2;
          int tile_y = 5;
          tileset.getSprite()->setTextureRect(
            sf::IntRect({ 16 * tile_x, 16 * tile_y }, { 16, 16 }));
          break;
        }
        case 12:
        {
          int tile_x = 1;
          int tile_y = 5;
          tileset.getSprite()->setTextureRect(
            sf::IntRect({ 16 * tile_x, 16 * tile_y }, { 16, 16 }));
          break;
        }
        case 13:
        {
          int tile_x = 16;
          int tile_y = 2;
          tileset.getSprite()->setTextureRect(
            sf::IntRect({ 16 * tile_x, 16 * tile_y }, { 16, 16 }));
          break;
        }
        case 14:
        {
          int tile_x = 16+3;
          int tile_y = 2;
          tileset.getSprite()->setTextureRect(
            sf::IntRect({ 16 * tile_x, 16 * tile_y }, { 16, 16 }));
          break;
        }
        case 15:
        {
          int tile_x = 15;
          int tile_y = 2+3;
          tileset.getSprite()->setTextureRect(
            sf::IntRect({ 16 * tile_x, 16 * tile_y }, { 16, 16 }));
          break;
        }
        case 16:
        {
          int tile_x = 16 + 2;
          int tile_y = 2;
          tileset.getSprite()->setTextureRect(
            sf::IntRect({ 16 * tile_x, 16 * tile_y }, { 16, 16 }));
          break;
        }
        default:
             tileset.getSprite()->setTextureRect(sf::IntRect({ 0, 0 }, { 16, 16 }));
          break;
      }
      tileset.setPosition((32 * x) * 1.5, (32 * y) * 1.5);
      game_window.draw(*tileset.getSprite());
    }
  }

  drawText(0, "Controls", 50, sf::Color::White, { 320, 130 }, game_window);
  drawText(0, "W - Move Forward", 30, sf::Color::White, { 300, 200 }, game_window);
  drawText(0, "S - Move Backward", 30, sf::Color::White, { 300, 250 }, game_window);
  drawText(0, "A - Rotate Left", 30, sf::Color::White, { 300, 300 }, game_window);
  drawText(0, "D - Rotate Right", 30, sf::Color::White, { 300, 350 }, game_window);
  drawText(0, "Left Click - Fire Gun", 30, sf::Color::White, { 300, 400 }, game_window);
    drawText(0, "Esc - Return / Pause", 30, sf::Color::White, { 300, 600 }, game_window);

	game_window.draw(*p_tank_body.getSprite());
    game_window.draw(*p_tank_turret.getSprite());
    game_window.draw(*e_tank_body_1.getSprite());
    game_window.draw(*e_tank_turret_1.getSprite());

}