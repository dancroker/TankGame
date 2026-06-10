#include <SFML/Graphics.hpp>
#include "Game.h"
int main()
{
	sf::RenderWindow window( sf::VideoMode( { 900, 900 } ), "SFML works!" );

	Game game;

	while ( window.isOpen() )
	{
		window.clear();
		while (const std::optional event = window.pollEvent() )
		{
			if ( event->is<sf::Event::Closed>() )
				window.close();

			if (const auto* key = event->getIf<sf::Event::KeyPressed>())
            {
              game.keyPressed(*key);
            }
		}
        game.render(window);
		window.display();
	}
}
