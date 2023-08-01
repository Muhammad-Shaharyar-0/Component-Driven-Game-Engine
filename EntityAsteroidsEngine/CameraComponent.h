#pragma once
#include "Vector4.h"
#include "GameObjectComponent.h"
#include "Matrix4x4.h"
class CameraComponent : public GameObjectComponent
{

public:
	Datastructers::Matrix4x4 mView;
	Datastructers::Matrix4x4 mProj;

	Datastructers::Vector4 mEye;
	Datastructers::Vector4 mLookAt;
	Datastructers::Vector4 mUp;

	float mFOV;
	float mNear;
	float mFar;

	float mWidth;
	float mHeight;
	bool isCameraChanged = true;

	CameraComponent(GameObject* gob);
	virtual ~CameraComponent();

	// Setup function -- called when owner object is initialised (using its own Start method)
	virtual void Start();

	// Main update function (called every frame)
	virtual void Update(double deltaTime);

	// Message handler (called when message occurs)
	virtual void OnMessage(Message* msg);

	// Shutdown function -- called when owner object is destroyed
	virtual void End();
};

