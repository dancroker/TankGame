#include "Player.h"

Player::Player() 
{
  player_tank.setupTank(
	"assets/Ace Of Tanks Assets/Player/Player_5_body_1.png",
	"assets/Ace Of Tanks Assets/Player/Player_5_body_2.png",
	"assets/Ace Of Tanks Assets/Player/player_5_turret.png");
  player_tank.setPos({ 200, 200 });
}

Player::~Player() 
{}

void Player::movePlayer(
  sf::Vector2i movement_y, sf::Vector2i movement_x, float dt)
{
}


void Player::rotate(sf::Vector2i movement_x, float dt)
{
  /*if (movement_x.x != 0)
  {
    player_tank.setTankRotation(player_tank.getTankRotation() + player_tank.getTankRotationSpeed() * dt);
  }
  if (movement_x.y != 0)
  {
    player_tank.setTankRotation(player_tank.getTankRotation() - player_tank.getTankRotationSpeed() * dt);
  }
  player_tank.getBodySprite().setRotation(sf::degrees(player_tank.getTankRotation()));*/
  player_tank.rotateTank(movement_x, dt);
}

void Player::tankControl(sf::Vector2i movement_y, float dt)
{
  if (movement_y.y != 0)
  {
    player_tank.moveTank(1, dt);
  }
  if (movement_y.x != 0)
  {
    player_tank.moveTank(-1, dt);
  }
}
void Player::update(float dt, sf::RenderWindow& window, sf::Vector2f aim_location)
{
  player_tank.updateTank(dt, window, aim_location);
  if (bullet.gethasFired())
  {
    bullet.move(dt);
  }
}
void Player::draw(sf::RenderWindow& window) 
{
        if (bullet.gethasFired())
        {
        window.draw(bullet.getSprite());
        }
    player_tank.drawTank(window);
}

void Player::fireGun()
{
  bullet.setLocation(static_cast<sf::Vector2i>(player_tank.getMuzzlePosition()));
  bullet.fire(player_tank.getTankTurretRotationRotation());
}