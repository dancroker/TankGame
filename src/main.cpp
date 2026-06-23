#include <SFML/Graphics.hpp>
#include "Game.h"
int main()
{
	sf::RenderWindow window( sf::VideoMode( { 900, 900 } ), "SFML works!" );

	Game game;
    sf::Clock clock;
	while ( window.isOpen() )
	{
		window.clear();

		sf::Time time = clock.restart();
        float dt      = time.asSeconds();

		while (const std::optional event = window.pollEvent() )
		{
			if ( event->is<sf::Event::Closed>() )
				window.close();

			if (const auto* key = event->getIf<sf::Event::KeyPressed>())
            {
              game.keyPressed(*key, window);
            }
            if (const auto* key = event->getIf<sf::Event::KeyReleased>())
            {
              game.keyReleased(*key);
            }
		}
        game.update(dt,window);
        game.render(window);
		window.display();
	}
}
