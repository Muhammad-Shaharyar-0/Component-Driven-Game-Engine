#include "BoxColliderComponent.h"

BoxColliderComponent::BoxColliderComponent(GameObject* gob)
	: GameObjectComponent("BoxCollider", gob)
{
}

BoxColliderComponent::~BoxColliderComponent()
{
}

void BoxColliderComponent::setBounds(Datastructers::Vector3 minBound, Datastructers::Vector3 maxBound)
{
	mMinBounds = minBound;
	mMaxBounds = maxBound;
}

void BoxColliderComponent::Start()
{
}

void BoxColliderComponent::Update(double deltaTime)
{
}

void BoxColliderComponent::OnMessage(Message* msg)
{
}

void BoxColliderComponent::End()
{
}
