#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class ScreenBase
{
public:
    ScreenBase();
    virtual ~ScreenBase();

    virtual void init();
    virtual void Update();
    virtual void Render();

    sf::Text TextCreator(int Font, sf::String text_include, int size, sf::Color text_colour, sf::Vector2f location);
    void drawText(int Font, sf::String text_include, int size, sf::Color text_colour, sf::Vector2f location, sf::RenderWindow& window);

protected:
    sf::Font font;
};