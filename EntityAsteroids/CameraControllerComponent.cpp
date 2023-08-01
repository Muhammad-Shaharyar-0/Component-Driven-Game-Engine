#include "CameraControllerComponent.h"
#include "GameObject.h"
#include "Game.h"
#include "Camera.h"

using namespace Datastructers;

CameraControllerComponent::CameraControllerComponent(GameObject* gob)
	: GameObjectComponent("CameraController", gob)
{

}
CameraControllerComponent::~CameraControllerComponent()
{
}

void CameraControllerComponent::Start()
{

	_camera = (dynamic_cast<Camera*>(_owner))->_camera;
}

void CameraControllerComponent::Update(double deltaTime)
{
	
	if (mInputManager->KeyHeld(KEY::KEY_A))
	{
		_camera->mEye += Vector4(-2, 0, 0, 0) * deltaTime;
		_camera->mLookAt += Vector4(-2, 0, 0, 0) * deltaTime;
		_camera->isCameraChanged = true;
	}
	if (mInputManager->KeyHeld(KEY::KEY_D))
	{
		_camera->mEye += Vector4(2, 0, 0, 0) * deltaTime;
		_camera->mLookAt += Vector4(2, 0, 0, 0) * deltaTime;
		_camera->isCameraChanged = true;
	}
	if (mInputManager->KeyHeld(KEY::KEY_W))
	{
		_camera->mEye += Vector4(0, 0, 2, 0) * deltaTime;
		_camera->mLookAt += Vector4(0, 0, 2, 0) * deltaTime;
		_camera->isCameraChanged = true;
	}
	if (mInputManager->KeyHeld(KEY::KEY_S))
	{
		_camera->mEye += Vector4(0, 0, -2, 0) * deltaTime;
		_camera->mLookAt += Vector4(0, 0, -2, 0) * deltaTime;
		_camera->isCameraChanged = true;
	}
	if (mInputManager->KeyHeld(KEY::KEY_LEFT_SHIFT))
	{
		_camera->mEye += Vector4(0, -2, 0, 0) * deltaTime;
		_camera->mLookAt += Vector4(0, -2, 0, 0) * deltaTime;
		_camera->isCameraChanged = true;
	}
	if (mInputManager->KeyHeld(KEY::KEY_SPACE))
	{
		_camera->mEye += Vector4(0, 2, 0, 0) * deltaTime;
		_camera->mLookAt += Vector4(0, 2, 0, 0) * deltaTime;
		_camera->isCameraChanged = true;
	}
	_camera->mView = LookAtLH(_camera->mEye, _camera->mLookAt, _camera->mUp);

}

void CameraControllerComponent::OnMessage(Message* msg)
{
}

void CameraControllerComponent::End()
{
}
