#include "CollisionSystem.h"
#include "GameObject.h"
#include "CollisionComponent.h"
#include "BoxColliderComponent.h"
#include "RayColliderComponent.h"
#include "CollisionMessage.h"

/******************************************************************************************************************/
// Structors
/******************************************************************************************************************/

CollisionSystem::CollisionSystem()
{
}

/******************************************************************************************************************/

CollisionSystem::~CollisionSystem()
{
}

/******************************************************************************************************************/
// Functions
/******************************************************************************************************************/

void CollisionSystem::Process(std::vector<GameObject*>& list, double deltaTime)
{
	for (size_t i = 0; i < list.size(); i++)
	{
		GameObject* collidee = list[i];

		if (!collidee->IsAlive()) continue; // Skip dead things
		
			if (RayColliderComponent* cc1 = (RayColliderComponent*)(collidee->GetComponent("RayCollider")))
			{
				RayToCubeCollision(cc1, list);
			}
		
		
		//// Does this object even have a Collision component?
		//if (CollisionComponent* cc1 = (CollisionComponent*)(collidee->GetComponent("collision")))
		//{
		//	if (cc1->GetCollisionID() == 0) continue; // Skip things with no collision ID

		//	// Collide against all objects we're meant to collide with
		//	for (size_t j = 0; j < list.size(); j++)
		//	{
		//		GameObject* collider = list[j];

		//		if (collidee == collider) continue; // Skip colliding against yourself
		//		if (!collider->IsAlive()) continue; // Skip dead things

		//		if (CollisionComponent* cc2 = (CollisionComponent*)(collider->GetComponent("collision")))
		//		{
		//			if (cc2->GetCollisionID() == 0) continue; // Skip things with no collision ID


		//			// Check collision matrix
		//			if (cc1->CheckCollisionMatrixFlag(cc2->GetCollisionID()))
		//			{
		//				// Collide with it...
		//				if (CollideWith(cc1, cc2))
		//				{
		//					// Send a collision message to both objects
		//					CollisionMessage msg(collidee, collider);
		//					collidee->OnMessage(&msg);
		//					collider->OnMessage(&msg);

		//					// break out of inner for loop
		//					break;
		//				}
		//			}
		//		}
		//	}
		//}
		// break ends up here
	}
}

void CalculateMinMaxT(float origin, float invDirection, float minBound, float maxBound, float& tMin, float& tMax)
{
	if (invDirection >= 0)
	{
		tMin = (minBound - origin) * invDirection;
		tMax = (maxBound - origin) * invDirection;
	}
	else
	{
		tMin = (maxBound - origin) * invDirection;
		tMax = (minBound - origin) * invDirection;
	}
}

void CollisionSystem::RayToCubeCollision(RayColliderComponent* collidiee, std::vector<GameObject*>& list)
{
	RayColliderComponent* rayCollider = collidiee;
	const Datastructers::Vector3 invDirection(1 / rayCollider->mDirection.X, 1 / rayCollider->mDirection.Y, 1 / rayCollider->mDirection.Z);

	for (size_t j = 0; j < list.size(); j++)
	{
	    GameObject* collider = list[j];
	
		if (collidiee->GetGameObject() == collider) continue; // Skip colliding against yourself
		if (!collider->IsAlive()) continue; // Skip dead things

		if (BoxColliderComponent* cc2 = (BoxColliderComponent*)(collider->GetComponent("BoxCollider")))
		{
			//check mouse ray against all collidables
			BoxColliderComponent* boxCollider = cc2;
			Datastructers::Vector4 origin = rayCollider->mOrigin;

			float txMin, txMax;
			float tyMin, tyMax;
			float tzMin, tzMax;

			// Calculate t values for x-axis
			CalculateMinMaxT(origin.X, invDirection.X, boxCollider->mMinBounds.X, boxCollider->mMaxBounds.X, txMin, txMax);

			// Calculate t values for y-axis
			CalculateMinMaxT(origin.Y, invDirection.Y, boxCollider->mMinBounds.Y, boxCollider->mMaxBounds.Y, tyMin, tyMax);

			// If no hit then continue
			if (txMin > tyMax || tyMin > txMax)
				continue;

			// Update highest min and lowest max
			float highestMin = (tyMin > txMin) ? tyMin : txMin;
			float lowestMax = (tyMax < txMax) ? tyMax : txMax;

			// Calculate t values for z-axis
			CalculateMinMaxT(origin.Z, invDirection.Z, boxCollider->mMinBounds.Z, boxCollider->mMaxBounds.Z, tzMin, tzMax);

			// If no hit then continue
			if (highestMin > tzMax || tzMin > lowestMax)
				continue;

			CollisionMessage msg(collidiee->GetGameObject(), collider);
			collidiee->GetGameObject()->SetAlive(false);
			collidiee->GetGameObject()->SetDeleteFlag(true);
			collider->OnMessage(&msg);
			break;
		}
	}
	collidiee->GetGameObject()->SetAlive(false);
	collidiee->GetGameObject()->SetDeleteFlag(true);
}

/******************************************************************************************************************/

bool CollisionSystem::CollideWith(const CollisionComponent* collidee, const CollisionComponent* collider)
{
	Datastructers::Vector4 diff = collider->GetGameObject()->GetPosition();
	diff -= collidee->GetGameObject()->GetPosition();

	return 0;// (diff.length() < collidee->GetCollisionRadius() + collider->GetCollisionRadius());
}

/******************************************************************************************************************/
