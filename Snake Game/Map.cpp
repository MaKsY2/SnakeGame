#include "Map.h"
#include "Object.h"

#include <vector>

#include "Food.h"
#include "Wall.h"
#include "Void.h"

Map::Map(int height, int weight):
	mField				(height,std::vector<Object*>(weight,NULL))
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < weight; j++)
		{
			if (i == 0 || j == 0 || i == height - 1 || j == weight - 1)
			{
				setObject(new Wall(), std::make_pair(i, j));
			}
			else
			{
				setObject(new Void(), std::make_pair(i, j));
			}
		}
	}
	setObject(new Food(), newRandCoords());
}

Map::~Map()
{
}

void
Map::newEmptyMap()
{
	for (int i = 0; i < mField.size(); i++)
	{
		for (int j = 0; j <	mField[0].size(); j++)
		{
			if (i == 0 || j == 0 || i == mField.size() - 1 || j == mField[0].size() - 1)
			{
				setObject(new Wall(), std::make_pair(i, j));
			}
			else
			{
				setObject(new Void(), std::make_pair(i, j));
			}
		}
	}
}

std::vector<std::vector<int>>
Map::getField()
{
	std::vector<std::vector<int>> result;
	for (auto i : mField)
	{
		result.push_back({});
		for (auto j : i)
		{
			result.back().push_back(j->getType());
		}
	}
	return result;
}

void
Map::setObject(Object* obj, std::pair<int, int> newCoord)
{
	delete(mField[newCoord.first][newCoord.second]);
	mField[newCoord.first][newCoord.second] = obj;
}


std::pair<int, int>
Map::newRandCoords()
{
	std::pair<int, int> newCoords(rand() % mField.size(), rand() % mField[0].size());
	while (mField[newCoords.first][newCoords.second]->getType() != ObjectType::VOID)
	{
		newCoords.first = rand() % mField.size();
		newCoords.second = rand() % mField[0].size();
	}
	return newCoords;
}