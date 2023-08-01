#include "CameraComponent.h"

CameraComponent::CameraComponent(GameObject* gob) 
	: GameObjectComponent("Camera", gob)
{
	mEye = Datastructers::Vector4(0.0f, 0.0f, -40.0f, 1.0f);
	mLookAt = Datastructers::Vector4(0.0f, 0.0f, 1.0f, 1.0f);
	mUp = Datastructers::Vector4(0.0f, 1.0f, 0.0f, 1.0f);
	mFOV = 60;
	mNear = 1;
	mFar = 500;
}

CameraComponent::~CameraComponent()
{
}

void CameraComponent::Start()
{
}

void CameraComponent::Update(double deltaTime)
{
}

void CameraComponent::OnMessage(Message* msg)
{
}

void CameraComponent::End()
{
}
