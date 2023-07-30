#pragma once
#include "GameObject.h"
#include "Colour.h"

class Mesh;
class Message;

class Voxel :
	public GameObject
{
	// Constants
public:
	Colour color= Colour(1.0,0.0,0.0);
	float mass=1;

	// Data
protected:

	// Structors
public:
	Voxel(Mesh* mesh);
	virtual ~Voxel();

	// Functions
public:
	virtual void Update(double deltaTime);
	virtual void OnMessage(Message* msg);
	virtual void Reset();
};

