#include "Bullet.h"

Bullet::Bullet() 
{
	bullet_object.initialiseSprite("assets/Ace Of Tanks Assets/Effects/Bullets/big_bullet.png");
  bullet_object.getSprite()->setScale({ 2, 2 });
}
Bullet::~Bullet() {}

void Bullet::setLocation(sf::Vector2i location) 
{
  bullet_object.setPosition(location.x, location.y);
}

void Bullet::fire(float tank_rotation) 
{
    x_fire_location = cos((tank_rotation - 90.f) * 3.14159265358979323846f / 180.f);
    y_fire_location = sin((tank_rotation - 90.f) * 3.14159265358979323846f / 180.f);

    bullet_object.getSprite()->setOrigin(
      { bullet_object.getSprite()->getGlobalBounds().size.x,
        bullet_object.getSprite()->getGlobalBounds().size.y });
    bullet_object.getSprite()->setRotation(sf::degrees(tank_rotation));
    bullet_object.getSprite()->setOrigin({ 0, 0 });
    hasFired = true;
}

void Bullet::move(float dt) 
{
  if (hasFired)
  {
      bullet_object.getSprite()->move({ (x_fire_location * speed)*dt, (y_fire_location * speed)*dt });
  }   
}

sf::Sprite Bullet::getSprite() 
{
  return *bullet_object.getSprite();
}



