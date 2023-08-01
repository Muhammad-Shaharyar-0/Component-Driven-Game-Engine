#pragma once
#include "Vector4.h"
#include "GameObjectComponent.h"

class CameraComponent : public GameObjectComponent
{

public:
	Datastructers::Vector4 mEye;
	Datastructers::Vector4 mLookAt;
	Datastructers::Vector4 mUp;

	float mFOV;
	float mNear;
	float mFar;


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

