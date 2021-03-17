
#pragma once
#pragma once
#include <sfml\Graphics.hpp>
#include <string>
#define MAX_ITEM 3


class menulose
{
public:
	menulose(float width, float height);
	~menulose();

	void draw(sf::RenderWindow& window);
	void MoveUp();
	void MoveDown();
	int GetPressItem() { return selectecItem; }


private:
	int selectecItem = 0;
	sf::Font font;
	sf::Text menu[MAX_ITEM];  //logo start exit
};

