#pragma once
#include "GameObjectComponent.h"
#include "Vector4.h"

class PhysicsComponent
	: public GameObjectComponent
{
	// Data
protected:
	Datastructers::Vector4			_velocity;	// Velocity of object
	float			_maxSpeed;  // Maximum speed


	// Structors
public:
	PhysicsComponent(GameObject* gob);
	virtual ~PhysicsComponent();

	// Gets/Sets
public:
	Datastructers::Vector4 GetVelocity()	const	{ return _velocity; }
	void SetVelocity(Datastructers::Vector4 v)		{ _velocity = v; }

	float GetMaxSpeed()		const	{ return _maxSpeed; }
	void SetMaxSpeed(float f)		{ _maxSpeed = f; }

	// Functions
public:

	// Setup function -- called when owner object is initialised (using its own Start method)
	virtual void Start();

	// Main update function (called every frame)
	virtual void Update(double deltaTime);

	// Message handler (called when message occurs)
	virtual void OnMessage(Message* msg);

	// Shutdown function -- called when owner object is destroyed
	virtual void End();

	// Extra Functions
public:
	void LimitToMaximumSpeed(float max);
	Datastructers::Vector4 GetObjectPosition();
	void SetObjectPosition(Datastructers::Vector4 v);
};