#ifndef SNAKE_H
#define SNAKE_H

#include "Object.h"

enum Direction
{
	UP,
	RIGHT,
	DOWN,
	LEFT
};

class Snake:public Object
{
public:
	Snake();
	~Snake();

	Direction getDirect();

private:
	Direction mDirect;

};




#endif // !SNAKE_H
