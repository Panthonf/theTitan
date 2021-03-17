#include "menulose.h"

menulose::menulose(float width, float height)
{
	if (!font.loadFromFile("font/f1.ttf"))
	{

	}

	this->menu[1].setFont(font);
	this->menu[1].setCharacterSize(80);
	this->menu[1].setFillColor(sf::Color::Yellow);
	this->menu[1].setString("PLAY AGAIN");
	this->menu[1].setOrigin(menu[1].getLocalBounds().width / 2, this->menu[1].getLocalBounds().height / 2);
	this->menu[1].setPosition(sf::Vector2f(width / 2, height / (MAX_ITEM + 1) * 2));

	this->menu[2].setFont(font);
	this->menu[2].setCharacterSize(60);
	this->menu[2].setFillColor(sf::Color::Yellow);
	this->menu[2].setString("EXIT");
	this->menu[2].setOrigin(menu[2].getLocalBounds().width / 2, this->menu[2].getLocalBounds().height / 2);
	this->menu[2].setPosition(sf::Vector2f(width / 2, height / (MAX_ITEM + 1) * 3));

	selectecItem = 0;
}

menulose ::~menulose()
{

}

void menulose::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < MAX_ITEM; i++)
	{
		window.draw(menu[i]);
	}
}

void menulose::MoveUp()
{
	if (selectecItem - 1 >= 0)
	{
		this->menu[selectecItem].setFillColor(sf::Color::Yellow);
		selectecItem--;
		this->menu[selectecItem].setFillColor(sf::Color::Red);

	}
}

void menulose::MoveDown()
{
	if (selectecItem + 1 < MAX_ITEM)
	{
		this->menu[selectecItem].setFillColor(sf::Color::Yellow);
		selectecItem++;
		this->menu[selectecItem].setFillColor(sf::Color::Red);

	}
}
