#include "Object.h"



Object::Object(ObjectType aType):
	mType	(aType)
{
}

Object::~Object()
{
}

ObjectType
Object::getType()
{
	return mType;
}