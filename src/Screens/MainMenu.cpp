#include "MainMenu.h"
#include "ControlMenu.h"

MainMenu::MainMenu() {}

MainMenu::~MainMenu() {}

void MainMenu::init()
{
}

void MainMenu::Update() {}

int MainMenu::Input(const sf::Event::KeyPressed& key)
{
  if (key.code == sf::Keyboard::Key::W)
  {
    if (option_selected > 0)
	  {
		  option_selected--;
      }
  }
  if (key.code == sf::Keyboard::Key::S)
  {
	  if (option_selected < 2)
	  {
		  option_selected++;
      }
  }
  if (key.code == sf::Keyboard::Key::Enter)
  {
    return option_selected;
  }
  return 99;
}

void MainMenu::Render(sf::RenderWindow& game_window)
{
	drawText(0, "Main Menu", 50, sf::Color::White, sf::Vector2f(310, 100), game_window);
  sf::Color text_colour_1 = sf::Color::White;
    sf::Color text_colour_2 = sf::Color::White;
  sf::Color text_colour_3 = sf::Color::White;
  if (option_selected == 0)
  {
	text_colour_1 = sf::Color::Yellow;
  }
  else if (option_selected == 1)
  {
	text_colour_2 = sf::Color::Yellow;
  }
  else if (option_selected == 2)
  {
	text_colour_3 = sf::Color::Yellow;
  }
  drawText(0, "Play", 50, text_colour_1, sf::Vector2f(400, 500), game_window);
  drawText(0, "Control", 50, text_colour_2, sf::Vector2f(360, 600), game_window);
  drawText(0, "Exit", 50, text_colour_3, sf::Vector2f(400, 700), game_window);
}