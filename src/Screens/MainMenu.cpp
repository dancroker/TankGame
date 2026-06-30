#include "MainMenu.h"
#include "ControlMenu.h"

MainMenu::MainMenu() 
{
  init();
}

MainMenu::~MainMenu() {}

void MainMenu::init()
{
  tileset.initialiseSprite("assets/Ace Of Tanks Assets/tileset.png");
  tileset.setPosition(0, 0);
  tileset.getSprite()->setScale({ 3, 3 });

  p_tank_body.initialiseSprite("assets/Ace Of Tanks Assets/Player/Player_1_body_1.png");
  p_tank_body.setPosition(725, 200);
  p_tank_body.getSprite()->setScale({ 3.0, 3.0 });
  p_tank_body.getSprite()->setRotation(sf::degrees(190));

  p_tank_turret.initialiseSprite("assets/Ace Of Tanks Assets/Player/Player_1_turret.png");
  p_tank_turret.setPosition(620, 200);
  p_tank_turret.getSprite()->setScale({ 3.0, 3.0 });
  p_tank_turret.getSprite()->setRotation(sf::degrees(245));

  p2_tank_body.initialiseSprite("assets/Ace Of Tanks Assets/Player/Player_2_body_1.png");
  p2_tank_body.setPosition(225, 225);
  p2_tank_body.getSprite()->setScale({ 3.0, 3.0 });
  p2_tank_body.getSprite()->setRotation(sf::degrees(100));

  p2_tank_turret.initialiseSprite("assets/Ace Of Tanks Assets/Player/Player_2_turret.png");
  p2_tank_turret.setPosition(230, 190);
  p2_tank_turret.getSprite()->setScale({ 3.0, 3.0 });
  p2_tank_turret.getSprite()->setRotation(sf::degrees(70));

  p3_tank_body.initialiseSprite("assets/Ace Of Tanks Assets/Player/Player_5_body_1.png");
  p3_tank_body.setPosition(300, 670);
  p3_tank_body.getSprite()->setScale({ 3.0, 3.0 });
  p3_tank_body.getSprite()->setRotation(sf::degrees(80));

  p3_tank_turret.initialiseSprite("assets/Ace Of Tanks Assets/Player/Player_5_turret.png");
  p3_tank_turret.setPosition(350, 690);
  p3_tank_turret.getSprite()->setScale({ 3.0, 3.0 });
  p3_tank_turret.getSprite()->setRotation(sf::degrees(90));

    p4_tank_body.initialiseSprite("assets/Ace Of Tanks Assets/Player/Player_6_body_1.png");
  p4_tank_body.setPosition(500, 600);
  p4_tank_body.getSprite()->setScale({ 3.0, 3.0 });
  p4_tank_body.getSprite()->setRotation(sf::degrees(190));

  p4_tank_turret.initialiseSprite("assets/Ace Of Tanks Assets/Player/Player_6_turret.png");
  p4_tank_turret.setPosition(425, 625);
  p4_tank_turret.getSprite()->setScale({ 3.0, 3.0 });
  p4_tank_turret.getSprite()->setRotation(sf::degrees(220));
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
  
    drawBackground(game_window);
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
  drawText(0, "Play", 50, text_colour_1, sf::Vector2f(725, 500), game_window);
  drawText(0, "Control", 50, text_colour_2, sf::Vector2f(695, 600), game_window);
  drawText(0, "Exit", 50, text_colour_3, sf::Vector2f(725, 700), game_window);
  game_window.draw(*p_tank_body.getSprite());
  game_window.draw(*p_tank_turret.getSprite());
  game_window.draw(*p2_tank_body.getSprite());
  game_window.draw(*p2_tank_turret.getSprite());
  game_window.draw(*p3_tank_body.getSprite());
  game_window.draw(*p3_tank_turret.getSprite());
  game_window.draw(*p4_tank_body.getSprite());
  game_window.draw(*p4_tank_turret.getSprite());
}

void MainMenu::drawBackground(sf::RenderWindow& game_window) 
{
  for (int x = 0; x < 19; x++)
  {
    for (int y = 0; y < 19; y++)
    {
      switch (background[y][x])
      {
        case 0:
        {
          int tile_x = 13;
          int tile_y = 2;
          tileset.getSprite()->setTextureRect(
            sf::IntRect({ 16 * tile_x, 16 * tile_y }, { 16, 16 }));
          break;
        }
        case 1:
        {
          int tile_x = 13 + 2;
          int tile_y = 2 + 4;
          tileset.getSprite()->setTextureRect(
            sf::IntRect({ 16 * tile_x, 16 * tile_y }, { 16, 16 }));
          break;
        }
        case 3:
        {
          int tile_x = 13 + 3;
          int tile_y = 2;
          tileset.getSprite()->setTextureRect(
            sf::IntRect({ 16 * tile_x, 16 * tile_y }, { 16, 16 }));
          break;
        }
        case 2:
        {
          int tile_x = 13 + 2;
          int tile_y = 2 + 2;
          tileset.getSprite()->setTextureRect(
            sf::IntRect({ 16 * tile_x, 16 * tile_y }, { 16, 16 }));
          break;
        }
        case 10:
        {
          int tile_x = 13 + 3;
          int tile_y = 2 + 2;
          tileset.getSprite()->setTextureRect(
            sf::IntRect({ 16 * tile_x, 16 * tile_y }, { 16, 16 }));
          break;
        }
        case 4:
        {
          int tile_x = 13 + 2;
          int tile_y = 2 + 5;
          tileset.getSprite()->setTextureRect(
            sf::IntRect({ 16 * tile_x, 16 * tile_y }, { 16, 16 }));
          break;
        }
        case 5:
        {
          int tile_x = 13 + 6;
          int tile_y = 2;
          tileset.getSprite()->setTextureRect(
            sf::IntRect({ 16 * tile_x, 16 * tile_y }, { 16, 16 }));
          break;
        }
        case 6:
        {
          int tile_x = 13 + 5;
          int tile_y = 2;
          tileset.getSprite()->setTextureRect(
            sf::IntRect({ 16 * tile_x, 16 * tile_y }, { 16, 16 }));
          break;
        }
        case 11:
        {
          int tile_x = 13 + 6;
          int tile_y = 2 + 6;
          tileset.getSprite()->setTextureRect(
            sf::IntRect({ 16 * tile_x, 16 * tile_y }, { 16, 16 }));
          break;
        }
        case 12:
        {
          int tile_x = 13 + 2;
          int tile_y = 2 + 3;
          tileset.getSprite()->setTextureRect(
            sf::IntRect({ 16 * tile_x, 16 * tile_y }, { 16, 16 }));
          break;
        }
        case 7:
        {
          int tile_x = 13 - 2;
          int tile_y = 2 + 4;
          tileset.getSprite()->setTextureRect(
            sf::IntRect({ 16 * tile_x, 16 * tile_y }, { 16, 16 }));
          break;
        }
        case 8:
        {
          int tile_x = 13 - 3;
          int tile_y = 2 + 3;
          tileset.getSprite()->setTextureRect(
            sf::IntRect({ 16 * tile_x, 16 * tile_y }, { 16, 16 }));
          break;
        }
        case 13:
        {
          int tile_x = 13 - 3;
          int tile_y = 2 + 4;
          tileset.getSprite()->setTextureRect(
            sf::IntRect({ 16 * tile_x, 16 * tile_y }, { 16, 16 }));
          break;
        }
        case 9:
        {
          int tile_x = 2;
          int tile_y = 40;
          tileset.getSprite()->setTextureRect(
            sf::IntRect({ 16 * tile_x, 16 * tile_y }, { 16, 16 }));
          break;
        }
        case 14:
        {
          int tile_x = 1;
          int tile_y = 40;
          tileset.getSprite()->setTextureRect(
            sf::IntRect({ 16 * tile_x, 16 * tile_y }, { 16, 16 }));
          break;
        }
        case 15:
        {
          int tile_x = 1;
          int tile_y = 41;
          tileset.getSprite()->setTextureRect(
            sf::IntRect({ 16 * tile_x, 16 * tile_y }, { 16, 16 }));
          break;
        }
        case 16:
        {
          int tile_x = 2;
          int tile_y = 41;
          tileset.getSprite()->setTextureRect(
            sf::IntRect({ 16 * tile_x, 16 * tile_y }, { 16, 16 }));
          break;
        }
        case 17:
        {
          int tile_x = 1;
          int tile_y = 42;
          tileset.getSprite()->setTextureRect(
            sf::IntRect({ 16 * tile_x, 16 * tile_y }, { 16, 16 }));
          break;
        }
        case 18:
        {
          int tile_x = 2;
          int tile_y = 42;
          tileset.getSprite()->setTextureRect(
            sf::IntRect({ 16 * tile_x, 16 * tile_y }, { 16, 16 }));
          break;
        }
        case 19:
        {
          int tile_x = 2 + 1;
          int tile_y = 42 + 10;
          tileset.getSprite()->setTextureRect(
            sf::IntRect({ 16 * tile_x, 16 * tile_y }, { 16, 16 }));
          break;
        }
        case 20:
        {
          int tile_x = 3;
          int tile_y = 42 + 9;
          tileset.getSprite()->setTextureRect(
            sf::IntRect({ 16 * tile_x, 16 * tile_y }, { 16, 16 }));
          break;
        }
        case 21:
        {
          int tile_x = 2;
          int tile_y = 42 + 9;
          tileset.getSprite()->setTextureRect(
            sf::IntRect({ 16 * tile_x, 16 * tile_y }, { 16, 16 }));
          break;
        }
        case 22:
        {
          int tile_x = 2;
          int tile_y = 42 + 10;
          tileset.getSprite()->setTextureRect(
            sf::IntRect({ 16 * tile_x, 16 * tile_y }, { 16, 16 }));
          break;
        }
        case 23:
        {
          int tile_x = 1;
          int tile_y = 42 + 9;
          tileset.getSprite()->setTextureRect(
            sf::IntRect({ 16 * tile_x, 16 * tile_y }, { 16, 16 }));
          break;
        }
        case 24:
        {
          int tile_x = 1;
          int tile_y = 42 + 10;
          tileset.getSprite()->setTextureRect(
            sf::IntRect({ 16 * tile_x, 16 * tile_y }, { 16, 16 }));
          break;
        }
        case 25:
        {
          int tile_x = 6;
          int tile_y = 2;
          tileset.getSprite()->setTextureRect(
            sf::IntRect({ 16 * tile_x, 16 * tile_y }, { 16, 16 }));
          break;
        }
        case 26:
        {
          int tile_x = 6;
          int tile_y = 1;
          tileset.getSprite()->setTextureRect(
            sf::IntRect({ 16 * tile_x, 16 * tile_y }, { 16, 16 }));
          break;
        }
        case 27:
        {
          int tile_x = 5;
          int tile_y = 1;
          tileset.getSprite()->setTextureRect(
            sf::IntRect({ 16 * tile_x, 16 * tile_y }, { 16, 16 }));
          break;
        }
        case 28:
        {
          int tile_x = 5;
          int tile_y = 2;
          tileset.getSprite()->setTextureRect(
            sf::IntRect({ 16 * tile_x, 16 * tile_y }, { 16, 16 }));
          break;
        }
        case 29:
        {
          int tile_x = 5;
          int tile_y = 3;
          tileset.getSprite()->setTextureRect(
            sf::IntRect({ 16 * tile_x, 16 * tile_y }, { 16, 16 }));
          break;
        }
        case 30:
        {
          int tile_x = 6;
          int tile_y = 3;
          tileset.getSprite()->setTextureRect(
            sf::IntRect({ 16 * tile_x, 16 * tile_y }, { 16, 16 }));
          break;
        }
        case 31:
        {
          int tile_x = 2;
          int tile_y = 6;
          tileset.getSprite()->setTextureRect(
            sf::IntRect({ 16 * tile_x, 16 * tile_y }, { 16, 16 }));
          break;
        }
        case 32:
        {
          int tile_x = 1;
          int tile_y = 5;
          tileset.getSprite()->setTextureRect(
            sf::IntRect({ 16 * tile_x, 16 * tile_y }, { 16, 16 }));
          break;
        }
        default:
        {
          tileset.getSprite()->setTextureRect(
            sf::IntRect({ 0, 0 }, { 16, 16 }));
          break;
        }
      }
      tileset.setPosition((32 * x) * 1.5, (32 * y) * 1.5);
      game_window.draw(*tileset.getSprite());
    }
  }
}
