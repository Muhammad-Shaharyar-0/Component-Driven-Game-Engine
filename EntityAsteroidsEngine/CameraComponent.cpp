#include "CameraComponent.h"

CameraComponent::CameraComponent(GameObject* gob) 
	: GameObjectComponent("Camera", gob)
{
	mEye = Datastructers::Vector4(10.0f, 10.0f, -60.0f, 1.0f);
	mLookAt = Datastructers::Vector4(10.0f, 10.0f, 60.0f, 1.0f);
	mUp = Datastructers::Vector4(0.0f, 1.0f, 0.0f, 1.0f);
	mFOV = 60;
	mNear = 1;
	mFar = 500;
}

CameraComponent::~CameraComponent()
{
}

void CameraComponent::Reset()
{
	mEye = Datastructers::Vector4(10.0f, 10.0f, -60.0f, 1.0f);
	mLookAt = Datastructers::Vector4(10.0f, 10.0f, 60.0f, 1.0f);
	mUp = Datastructers::Vector4(0.0f, 1.0f, 0.0f, 1.0f);
	mFOV = 60;
	mNear = 1;
	mFar = 500;
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
