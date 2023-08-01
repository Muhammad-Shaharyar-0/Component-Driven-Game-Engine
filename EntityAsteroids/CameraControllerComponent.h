#pragma once
#include "GameObjectComponent.h"
#include "InputManager_DX.h"
#include "CameraComponent.h"

class CameraControllerComponent : public GameObjectComponent
{
//#ifdef DIRECTX
//	std::shared_ptr<InputManager_DX> mInputManager = InputManager_DX::Instance();
//#elif OPENGL
//	std::shared_ptr<InputManager_GL> mInputManager = InputManager_GL::Instance();
//#endif
	std::shared_ptr<InputManager_DX> mInputManager = InputManager_DX::Instance();
	CameraComponent* _camera;


public:
	CameraControllerComponent(GameObject* gob);

	virtual ~CameraControllerComponent();


	// Setup function -- called when owner object is initialised (using its own Start method)
	virtual void Start();

	// Main update function (called every frame)
	virtual void Update(double deltaTime);

	// Message handler (called when message occurs)
	virtual void OnMessage(Message* msg);

	// Shutdown function -- called when owner object is destroyed
	virtual void End();
};

