#include "EnemyBase.h"

EnemyBase::EnemyBase() 
{
  tank.setupTank(
    "assets/Ace Of Tanks Assets/Enemies/enemy_4_body_1.png",
    "assets/Ace Of Tanks Assets/Enemies/enemy_4_body_2.png",
    "assets/Ace Of Tanks Assets/Enemies/enemy_4_turret.png");
  tank.setPos({ 400, 400 });

}

EnemyBase::~EnemyBase() {}

void EnemyBase::draw(sf::RenderWindow& window)
{
  if (bullet.gethasFired())
  {
    window.draw(bullet.getSprite());
  }
  tank.drawTank(window);
}

void EnemyBase::update(float dt, sf::RenderWindow& window, sf::Vector2f aim_location)
{
  tank.updateTank(dt, window, aim_location);
  if (bullet.gethasFired())
  {
    bullet.move(dt);
  }
}

void EnemyBase::move() 
{
  std::list<sf::Vector2i> visited;
  std::list<sf::Vector2i> path;
  bfs(visited, path, { 400, 400 }, { 200, 200 });



}

void EnemyBase::bfs(std::list<sf::Vector2i> visited, std::list<sf::Vector2i> path, sf::Vector2i start, sf::Vector2i goal)
{
  visited.push_back(start);
  path.push_back(start);

  while (!path.empty())
  {
  }
}