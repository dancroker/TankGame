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

void Bullet::fire(float tank_rotation, sf::Vector2f position) 
{
  if (!hasFired)
  {
  
    x_fire_location = cos((tank_rotation - 90.f) * 3.14159265358979323846f / 180.f);
    y_fire_location = sin((tank_rotation - 90.f) * 3.14159265358979323846f / 180.f);
    setLocation(static_cast<sf::Vector2i>(position));
    bullet_object.getSprite()->setOrigin(
      { bullet_object.getSprite()->getGlobalBounds().size.x,
        bullet_object.getSprite()->getGlobalBounds().size.y });
    bullet_object.getSprite()->setRotation(sf::degrees(tank_rotation));
    bullet_object.getSprite()->setOrigin({ 0, 0 });
    hasFired = true;
    }
}

void Bullet::move(float dt, sf::RenderWindow& window) 
{
  if (hasFired)
  {
      bullet_object.getSprite()->move({ (x_fire_location * speed)*dt, (y_fire_location * speed)*dt });
      if (bullet_object.getSprite()->getPosition().x < 0 - bullet_object.getSprite()->getGlobalBounds().size.x || bullet_object.getSprite()->getPosition().x > (window.getSize().x + bullet_object.getSprite()->getGlobalBounds().size.x) ||
          bullet_object.getSprite()->getPosition().y < 0 - bullet_object.getSprite()->getGlobalBounds().size.y || bullet_object.getSprite()->getPosition().y > (window.getSize().y + bullet_object.getSprite()->getGlobalBounds().size.y))
      {
        remove();
      }
     
  }   
}

sf::Sprite Bullet::getSprite() 
{
  return *bullet_object.getSprite();
}

void Bullet::remove() 
{
  hasFired = false;
}

void Bullet::hitWall(sf::RenderWindow& window, sf::Vector2f location)
{
  remove();

}