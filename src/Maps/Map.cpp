#include "Map.h"

Map::Map() {}

Map::~Map() {}

void Map::drawMap(sf::RenderWindow& window) 
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 11; j++)
		{
			if (map_grid[i][j] == 0)
			{
              sf::RectangleShape floor({ tile_size, tile_size });
              floor.setPosition({ j * tile_size, i * tile_size });
				floor.setFillColor(sf::Color::Green);
				window.draw(floor);
			}
            if (map_grid[i][j] == 1)
            {
              sf::RectangleShape wall({ tile_size, tile_size });
              wall.setPosition({ j * tile_size, i * tile_size });
              wall.setFillColor(sf::Color::Blue);
              window.draw(wall);
            }
		}
    }
}

bool Map::isColliding(const sf::Sprite bounds) const
{
  for (int x = 0; x < 11; x++)
  {
      for (int y = 0; y < 11; y++)
      {
          if (map_grid[y][x] == 1)
          {
            sf::FloatRect tile_rect({x * tile_size, y * tile_size}, {tile_size, tile_size});
            if (tile_rect.contains(bounds.getPosition()))
              {
                  return true;
              }
          }
      }
  }
    return false;
}

int Map::isTankColliding(sf::Vector2f tank_points[4])
{
  for (int x = 0; x < 11; x++)
  {
    for (int y = 0; y < 11; y++)
    {
      if (map_grid[y][x] == 1)
      {
        sf::FloatRect tile_rect({ x * tile_size, y * tile_size }, { tile_size, tile_size });
        for (int point = 0; point < 4; point++)
        {
          if (tile_rect.contains(tank_points[point]))
          {
            return point;
          }
        }
      }
    }
  }
  return -1;
}

