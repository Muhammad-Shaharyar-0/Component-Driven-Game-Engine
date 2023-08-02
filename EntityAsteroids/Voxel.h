#pragma once
#include "GameObject.h"
#include "Colour.h"
#include "Components.h"

class Mesh;
class Message;

class Voxel :
	public GameObject
{
	// Constants
	BoxColliderComponent* cc;
	RenderComponent* rc;
public:
	Colour color= Colour(1.0f,0.0f,0.0f,0.0f);
	Colour stolencolor = Colour(0.0f, 1.0f, 0.0f, 0.0f);
	Colour initialcolor = Colour(1.0f, 0.0f, 0.0f, 0.0f);
	float initialmass;
	float mass=1;
	float size;

	// Data
protected:

	// Structors
public:
	Voxel(Mesh* mesh);
	virtual ~Voxel();
	void setBounds();
	// Functions
public:
	virtual void Update(double deltaTime);
	virtual void OnMessage(Message* msg);
	Datastructers::Vector4 LerpColors(const Datastructers::Vector4& color1, const Datastructers::Vector4& color2, float weight);
	virtual void Reset();
};

