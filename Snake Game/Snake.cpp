#include "Snake.h"

Snake::Snake():
	Object		(ObjectType::SNAKE),
	mDirect		(Direction::UP)
{



}

Direction
Snake::getDirect()
{
	return mDirect;
}

Snake::~Snake()
{
}