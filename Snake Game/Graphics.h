#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <SFML/Graphics.hpp>
#include <vector>


#define SQUARE_SIZE 50
#define SQUARE_CNT 10
#define FIELD_ROWS 5
#define FIELD_COLS 5

class Graphics
{
public:
	Graphics(sf::ContextSettings aSettings);
	virtual ~Graphics();
	void updateMap(std::vector<std::vector<int>> aMap);
	void testField(int testH, int testW);

private:
	sf::ContextSettings mSettings;
	sf::RenderWindow mWindow;
};



#endif // !GRAPHICS_H
