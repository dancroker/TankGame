#include "ControlMenu.h"
ControlMenu::ControlMenu() {}

ControlMenu::~ControlMenu() {}

void ControlMenu::init() 
{
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
  drawText(0, "Controls", 50, sf::Color::White, { 300, 100 }, game_window);
  drawText(0, "W - Move Forward", 30, sf::Color::White, { 300, 200 }, game_window);
  drawText(0, "S - Move Backward", 30, sf::Color::White, { 300, 250 }, game_window);
  drawText(0, "A - Rotate Left", 30, sf::Color::White, { 300, 300 }, game_window);
  drawText(0, "D - Rotate Right", 30, sf::Color::White, { 300, 350 }, game_window);
  drawText(0, "Left Click - Fire Gun", 30, sf::Color::White, { 300, 400 }, game_window);
    drawText(0, "Esc - Return / Pause", 30, sf::Color::White, { 300, 600 }, game_window);
}