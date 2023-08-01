#pragma once
#include "System.h"
#include <vector>
#include "RayColliderComponent.h"

class CollisionComponent;

// Moves objects around based on PhysicsComponents
class CollisionSystem :
	public System
{
	// Data
protected:


	// Structors
public:
	CollisionSystem();
	virtual ~CollisionSystem();

	// Get / sets
public:

	// Functions
public:
	bool CollideWith(const CollisionComponent* collidee, const CollisionComponent* collider);
	virtual void Process(std::vector<GameObject*>& list, double deltaTime);

private:
	void RayToCubeCollision(RayColliderComponent* collidiee, std::vector<GameObject*>& list);
};

