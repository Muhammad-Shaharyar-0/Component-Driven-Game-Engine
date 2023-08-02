#pragma once
#include "GameObject.h"
#include "CameraComponent.h"

class Camera :public GameObject
{

	// Constants
public:

	CameraComponent* _camera;
	int mCameraID;
	// Data
protected:

	// Structors
public:
	Camera();
	virtual ~Camera();

	// Functions
public:
	virtual void Reset();
	virtual void Update(double deltaTime);


};

