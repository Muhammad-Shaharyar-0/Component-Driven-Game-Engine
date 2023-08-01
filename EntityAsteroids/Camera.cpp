#include "Camera.h"
#include "CameraControllerComponent.h"
#include "Components.h"

Camera::Camera() : GameObject("Camera")
{
	_camera = new CameraComponent(this);
	new CameraControllerComponent(this);
	_alive = true;
	RenderComponent* rc = new RenderComponent(this);

}

Camera::~Camera()
{
	
	
}

void Camera::Update(double deltaTime)
{
	GameObject::Update(deltaTime);
}
