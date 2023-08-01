#pragma once
#include "Vector3.h"
#include "GameObjectComponent.h"

class BoxColliderComponent : public GameObjectComponent
{
	Datastructers::Vector3 mMinBounds;
	Datastructers::Vector3 mMaxBounds;

};

