#include "GameObject.h"

GameObject::GameObject()
{
  texture = new sf::Texture();
}
GameObject::~GameObject()
{
  delete texture;
  delete sprite;
}

void GameObject::setVisible(bool visible)
{
  is_visible = visible;
}

bool GameObject::getVisible()
{
  return is_visible;
}

bool GameObject::initialiseSprite(std::string filename)
{
  texture->loadFromFile(filename);
  sprite = new sf::Sprite(*texture);
  return true;
}

sf::Sprite* GameObject::getSprite()
{
  return sprite;
}

void GameObject::setPosition(float x, float y)
{
  sprite->setPosition({x,y});
}