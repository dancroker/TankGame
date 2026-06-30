#pragma once
#include <SFML/Graphics.hpp>

class Map
{
 public:
  Map();
  ~Map();
  void drawMap(sf::RenderWindow& window);

  bool isBulletColliding(const sf::Vector2f location) const;
  int isTankColliding(sf::Vector2f tank_points[4]);
  int (*getWholeMapGrid()) { return *map_grid; }

  // Returns true when the given world-space bounding rectangle overlaps a solid tile.

 private:
  float tile_size        = 16*5;
  int map_grid[11][11] = {
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0 },
    { 0, 0, 0, 0, 1, 1, 1, 1, 0, 0,0 }, 
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0 }, 
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0 },
    { 0, 1, 0, 0, 0, 0, 0, 0, 0, 0,0 }, 
    { 0, 1, 1, 1, 1, 1, 1, 1, 0, 0,0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0 }, 
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }

  };
};
