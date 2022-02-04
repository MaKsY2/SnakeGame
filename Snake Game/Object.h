#ifndef OBJECT_H
#define OBJECT_H

#define OBJECTS_CNT 4

enum ObjectType
{
	FOOD,
	VOID,
	SNAKE,
	WALL
};

class Object
{
public:
	Object(ObjectType aType);
	virtual ~Object();
	ObjectType getType();

private:
	ObjectType mType;
};



#endif // !OBJECT_H
