#include "CameraControllerComponent.h"


CameraControllerComponent::CameraControllerComponent(GameObject* gob)
	: GameObjectComponent("CameraController", gob)
{

}
CameraControllerComponent::~CameraControllerComponent()
{
}

void CameraControllerComponent::Start()
{
}

void CameraControllerComponent::Update(double deltaTime)
{
	//if (mInputManager->KeyHeld(KEY::KEY_A))
	//{
	//	/*mEye += Vector4(-2, 0, 0, 0) * deltaTime;
	//	mLookAt += Vector4(-2, 0, 0, 0) * deltaTime;*/

	//}
	//if (mInputManager->KeyHeld(KEY::KEY_D))
	//{
	//	mEye += Vector4(2, 0, 0, 0) * deltaTime;
	//	mLookAt += Vector4(2, 0, 0, 0) * deltaTime;
	//}
	//if (mInputManager->KeyHeld(KEY::KEY_W))
	//{
	//	mEye += Vector4(0, 0, 2, 0) * deltaTime;
	//	mLookAt += Vector4(0, 0, 2, 0) * deltaTime;
	//}
	//if (mInputManager->KeyHeld(KEY::KEY_S))
	//{
	//	mEye += Vector4(0, 0, -2, 0) * deltaTime;
	//	mLookAt += Vector4(0, 0, -2, 0) * deltaTime;
	//}
	//if (mInputManager->KeyHeld(KEY::KEY_LEFT_SHIFT))
	//{
	//	mEye += Vector4(0, -2, 0, 0) * deltaTime;
	//	mLookAt += Vector4(0, -2, 0, 0) * deltaTime;
	//}
	//if (mInputManager->KeyHeld(KEY::KEY_SPACE))
	//{
	//	mEye += Vector4(0, 2, 0, 0) * deltaTime;
	//	mLookAt += Vector4(0, 2, 0, 0) * deltaTime;
	//}
	//mEcsManager->TransformComp(mCameraID)->mTranslation = mEye;
	//mEcsManager->CameraComp(mCameraID)->mLookAt = mLookAt;
	//mView = LookAtLH(mEye, mLookAt, mUp);
}

void CameraControllerComponent::OnMessage(Message* msg)
{
}

void CameraControllerComponent::End()
{
}
