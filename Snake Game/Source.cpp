#include "SFML/Graphics.hpp"

#include <iostream>

#include "Object.h"
#include "Wall.h"
#include "Food.h"
#include "Map.h"
#include "Graphics.h"





int main()
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	Graphics graph(settings);

	Map map(FIELD_ROWS, FIELD_COLS);
	graph.updateMap(map.getField());
	//graph.testField(FIELD_ROWS, FIELD_COLS);

	return 0;
}