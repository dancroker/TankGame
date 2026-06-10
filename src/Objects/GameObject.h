#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
class GameObject
{
 public:
  GameObject();
  ~GameObject();

  bool initialiseSprite(std::string filename);
  sf::Sprite* getSprite();
  void setPosition(float x, float y);
  void setVisible(bool visible);
  bool getVisible();

 private:
  sf::Texture* texture = nullptr;
  sf::Sprite* sprite   = nullptr;
  bool is_visible      = true;
};