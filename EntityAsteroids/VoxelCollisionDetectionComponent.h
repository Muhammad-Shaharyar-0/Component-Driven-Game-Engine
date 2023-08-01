#pragma once
#include "GameObjectComponent.h"
#include "GameObject.h"

class VoxelCollisionDetectionComponent : public GameObjectComponent
{
public:
#ifdef DIRECTX
	std::shared_ptr<InputManager_DX> mInputManager = InputManager_DX::Instance();
#elif OPENGL
	std::shared_ptr<InputManager_GL> mInputManager = InputManager_GL::Instance();
#endif

	std::vector<GameObject> mRays;

	VoxelCollisionDetectionComponent(GameObject* gob);

	virtual ~VoxelCollisionDetectionComponent();

	void CheckCollision();

	// Setup function -- called when owner object is initialised (using its own Start method)
	virtual void Start();

	// Main update function (called every frame)
	virtual void Update(double deltaTime);

	// Message handler (called when message occurs)
	virtual void OnMessage(Message* msg);

	// Shutdown function -- called when owner object is destroyed
	virtual void End();
};

