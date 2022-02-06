#include "Graphics.h"
#include "Object.h"


Graphics::Graphics(sf::ContextSettings aSettings) :
	mSettings		(aSettings),
	mWindow			(sf::VideoMode(1600, 900), "Snake_Game", sf::Style::Default, aSettings)
{

}

Graphics::~Graphics()
{
}

void 
Graphics::testField(int testH, int testW)
{
	while (mWindow.isOpen()) {

		sf::Event event;
		while (mWindow.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				mWindow.close();
		}

		mWindow.clear(sf::Color(0, 0, 0, 0));
		sf::RectangleShape square(sf::Vector2f(SQUARE_SIZE, SQUARE_SIZE));
		square.setOutlineThickness(3.f);
		square.setOutlineColor(sf::Color(212, 210, 213));

		for (int i = 0; i < testH; i++)
		{
			if (i) square.move(-1*SQUARE_SIZE*(testW-1), SQUARE_SIZE);
			for (int j = 0; j < testW; j++)
			{
				square.move(SQUARE_SIZE*bool(j), 0);
				mWindow.draw(square);
			}
		}

		mWindow.display();
	}
}

void
Graphics::updateMap(std::vector<std::vector<int>> aMap)
{
	while (mWindow.isOpen()) {

		sf::Event event;
		while (mWindow.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				mWindow.close();
		}

		std::vector<sf::Color> color(OBJECTS_CNT);
		color[ObjectType::FOOD] = sf::Color(162, 44, 41);
		color[ObjectType::SNAKE] = sf::Color(62, 160, 24);
		color[ObjectType::WALL] = sf::Color(0, 0, 0);
		color[ObjectType::VOID] = sf::Color(255, 255, 255);

		mWindow.clear(sf::Color(0, 0, 0, 0));
		sf::RectangleShape square(sf::Vector2f(SQUARE_SIZE, SQUARE_SIZE));
		square.setOutlineThickness(3.f);
		square.setOutlineColor(sf::Color(212, 210, 213));

		for (int i = 0; i < aMap.size(); i++)
		{
			float x = -1 * SQUARE_SIZE * (int(aMap[0].size()) - 1);
			float y = SQUARE_SIZE;
			if (i) square.move(x, y);
			for (int j = 0; j < aMap[0].size(); j++)
			{
				float x1 = SQUARE_SIZE * bool(j);
				float y1 = 0;
				square.move(x1, y1);
				mWindow.draw(square);
			}
		}
		mWindow.display();
	}
}