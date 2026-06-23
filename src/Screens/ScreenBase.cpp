#include "ScreenBase.h"

ScreenBase::ScreenBase()
{
  if (!font.openFromFile("assets/Fonts/OpenSans-Bold.ttf"))
  {
    std::cout << "Error loading font" << std::endl;
  }
}

ScreenBase::~ScreenBase() {}

void ScreenBase::init() {}

void ScreenBase::Update() {}
void ScreenBase::Render() {}

sf::Text ScreenBase::TextCreator(int Font, sf::String text_include, int size, sf::Color text_colour,
  sf::Vector2f location)
{
  sf::Text text(font);
  text.setFont(font);
  text.setString(text_include);
  text.setCharacterSize(size);
  text.setFillColor(text_colour);
  text.setPosition(location);

  return text;
}

void ScreenBase::drawText(int Font, sf::String text_include, int size, sf::Color text_colour, sf::Vector2f location, sf::RenderWindow& window)
{
  sf::Text text(font);
  text.setFont(font);
  text.setString(text_include);
  text.setCharacterSize(size);
  text.setFillColor(text_colour);
  text.setPosition(location);

  window.draw(text);
}
