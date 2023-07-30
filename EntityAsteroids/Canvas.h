#pragma once
#include "GameObject.h"
#include "Voxel.h"



class Canvas :public GameObject
{
	// Constants
public:

	int size = 50;
	std::vector<Voxel*> _voxels;

	// Data
protected:

	// Structors
public:
	Canvas(int _size);
	virtual ~Canvas();

	// Functions
public:
	virtual void Update(double deltaTime);
};

