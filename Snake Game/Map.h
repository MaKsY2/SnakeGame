#ifndef MAP_H
#define MAP_H

#include <vector>

#include "Object.h"

class Map
{
public:
	Map(int height, int weight);
	virtual ~Map();
	void setObject(Object* obj, std::pair<int, int> newCoord);
	std::pair<int, int> newRandCoords();
	std::vector<std::vector<int>> getField();
	void newEmptyMap();
private:
	std::vector<std::vector<Object*>> mField;
};



#endif // !MAP_H
