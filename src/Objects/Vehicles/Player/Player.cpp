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
    bullet.move(dt,window);
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
  bullet.fire(player_tank.getTankTurretRotationRotation(), player_tank.getMuzzlePosition());
}

sf::Vector2f Player::getBulletLocation() 
{
  bullet.getSprite().setOrigin({ bullet.getSprite().getGlobalBounds().size.x / 2,
                                 bullet.getSprite().getGlobalBounds().size.y / 2});

  sf::Vector2f bullet_location = bullet.getSprite().getPosition();
  bullet.getSprite().setOrigin({ 0, 0 });
  return bullet_location;
}
