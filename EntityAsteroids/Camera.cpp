#include "Camera.h"
#include "CameraControllerComponent.h"

Camera::Camera() : GameObject("Camera")
{
	_camera = new CameraComponent(this);
	new CameraControllerComponent(this);

}

Camera::~Camera()
{
	
	
}

void Camera::Update(double deltaTime)
{
	GameObject::Update(deltaTime);
}
