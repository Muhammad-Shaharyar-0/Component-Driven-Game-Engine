#include "RayColliderComponent.h"

RayColliderComponent::RayColliderComponent(GameObject* gob)
	: GameObjectComponent("RayCollider", gob)
{
}

RayColliderComponent::RayColliderComponent(GameObject* gob, Datastructers::Vector4 start, Datastructers::Vector4 dir)
	: GameObjectComponent("RayCollider", gob)
{
	mOrigin = start;
	mDirection = dir;
}

RayColliderComponent::~RayColliderComponent()
{
}

void RayColliderComponent::Start()
{
}

void RayColliderComponent::Update(double deltaTime)
{
}

void RayColliderComponent::OnMessage(Message* msg)
{
}

void RayColliderComponent::End()
{
}
