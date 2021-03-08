#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace std;

int main()
{
	sf::RenderWindow window(sf::VideoMode(1080,720), "The Titan Project !!!");

	//////music
	sf::Music music;
	if (!music.openFromFile("sound/01.wav"))
	{
		cout << "Music cann't play ";
	}
	music.play();



	///////TextureBackground
	sf::Texture background;
	if (!background.loadFromFile("image/pi1.png"))
	{
		std::cout << "Load failed" << std::endl;
	}
	//////BackgroundSprite
	sf::Sprite backgroundsprite;
	backgroundsprite.setTexture(background);

	////// Texture
	sf::Texture playerTexture;
	if (!playerTexture.loadFromFile("image/sprite.png"))
	{
		std::cout << "Load failed" << std::endl;
	}

	////// Sprite
	sf::Sprite shapeSprite;
	shapeSprite.setTexture(playerTexture);


	int spriteSizeX = playerTexture.getSize().x / 3;
	int spriteSizeY = playerTexture.getSize().y / 4;

	shapeSprite.setTextureRect(sf::IntRect(0, 0, spriteSizeX, spriteSizeY));

	sf::Vector2f spawnPoint = { 50.f, 500.f };
	shapeSprite.setPosition(spawnPoint);
	int animationFrame = 0;


	
	

	while (window.isOpen())
	{
		window.draw(backgroundsprite);
		window.draw(shapeSprite);

		///// RandomSprite
		
		float x = std::rand() % 915 + 1; // dist is the visible width of the screen
		float y = 300;
		shapeSprite.setPosition(x, y); //spawn location of enemy
			

		window.display();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			if (shapeSprite.getPosition().x < 1850) 
			{
				shapeSprite.move(+0.25f, 0.f);
				shapeSprite.setTextureRect(sf::IntRect(spriteSizeX * animationFrame, spriteSizeY * 1, spriteSizeX, spriteSizeY));
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{	
			if (shapeSprite.getPosition().x > 0) 
			{
				shapeSprite.move(-0.25f, 0.f);
				shapeSprite.setTextureRect(sf::IntRect(spriteSizeX * animationFrame, spriteSizeY * 3, spriteSizeX, spriteSizeY));
			}
		}


			
			
		

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			window.close();
		}
		animationFrame++;

		if (animationFrame >= 2) {
			animationFrame = 0;
		}

		window.clear();
	}
	return 0;
}