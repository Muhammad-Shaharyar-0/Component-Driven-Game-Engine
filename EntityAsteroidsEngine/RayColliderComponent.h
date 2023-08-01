#pragma once
#include "MatrixMath.h"
#include "GameObjectComponent.h"

class RayColliderComponent: public GameObjectComponent
{


	// Structors
public:
	Datastructers::Vector4 mOrigin;
	Datastructers::Vector4 mDirection;

	int		_collisionMatrix;	// Who to collide with (bitfields)
	int		_collisionID;		// This object's collision type

	RayColliderComponent(GameObject* gob);
	RayColliderComponent(GameObject* gob, Datastructers::Vector4 start, Datastructers::Vector4 dir);
	virtual ~RayColliderComponent();


	// Gets/Sets
public:

	// Collision matrix
	void SetCollisionMatrixFlag(int flag) { _collisionMatrix |= flag; }
	void UnsetCollisionMatrixFlag(int flag) { _collisionMatrix &= ~flag; }
	bool CheckCollisionMatrixFlag(int flag)	const { return (_collisionMatrix & flag) != 0; }
	int GetCollisionMatrix()				const { return _collisionMatrix; }

	// Collision ID
	int GetCollisionID()					const { return _collisionID; }
	void SetCollisionID(int id) { _collisionID = id; }

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
};

