#pragma once
#include "../Tank.h"
#include "../../Projectiles/Bullet.h"
#include <list>
class EnemyBase
{
public:
  EnemyBase();
  ~EnemyBase();

  void draw(sf::RenderWindow& window);
  void update(float dt, sf::RenderWindow& window, sf::Vector2f aim_location);
  Tank& getTank() { return tank; };
  void move();
  void bfs(std::list<sf::Vector2i> visited, std::list<sf::Vector2i> path, sf::Vector2i start, sf::Vector2i goal);

private:
  Tank tank;
  Bullet bullet;
};
