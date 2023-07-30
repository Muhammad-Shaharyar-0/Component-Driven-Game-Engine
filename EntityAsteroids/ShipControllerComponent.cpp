#include "ShipControllerComponent.h"
#include "GameObject.h"
#include "Game.h"
#include "Bullet.h"
#include "KeyPressMessage.h"
#include "ThrustMessage.h"
#include "Voxel.h"

const float ShipControllerComponent::ACCELERATION = 1.0f;

/******************************************************************************************************************/
// Structors
/******************************************************************************************************************/

ShipControllerComponent::ShipControllerComponent(GameObject* gob)
	: UserInputComponent(gob),
	_turnLeftPressed(false),
	_turnRightPressed(false),
	_acceleratePressed(false)
{
	// Create 5 bullets
	for (int i = 0; i < NUM_BULLETS; i++)
	{
		_bullets[i] = new Bullet(ResourceManager::Instance()->GetMesh("bullet"));
		_bullets[i]->SetAlive(false);
		Game::TheGame->AddGameObject(_bullets[i]);
	}
}

/******************************************************************************************************************/

ShipControllerComponent::~ShipControllerComponent()
{
	// Bullets deleted by the game
}

/******************************************************************************************************************/
// Functions
/******************************************************************************************************************/

// Setup function -- called when owner object is initialised (using its own Start method)
void ShipControllerComponent::Start()
{
	// Register as a listener
	_owner->RegisterListener("keypress", this);

	for (int i = 0; i < NUM_BULLETS; i++)
	{
		_bullets[i]->Start();
	}

}

/******************************************************************************************************************/

// Main update function (called every frame)
void ShipControllerComponent::Update(double deltaTime)
{
	if (_turnLeftPressed)	// Left
	{
		TurnLeft((float)(180.0f * deltaTime));
	}
	if (_turnRightPressed)	// Right
	{
		TurnRight((float)(180.0f * deltaTime));
	}
	if (_acceleratePressed)	// Up
	{
		Accelerate((float)(ACCELERATION * deltaTime));
	}
}

/******************************************************************************************************************/

// Message handler (called when message occurs)
void ShipControllerComponent::OnMessage(Message* msg)
{
	if (msg->GetMessageType() == "keypress")
	{
		KeyPressMessage* kpm = (KeyPressMessage*)msg;
		switch (kpm->GetKey())
		{
			case 37: // Left
				_turnLeftPressed = kpm->GetDown();
				break;
			case 39: // Right
				_turnRightPressed = kpm->GetDown();
				break;
			case 38: // Up
				_acceleratePressed = kpm->GetDown();
				break;
			case 17: // Ctrl
			case 32: // Space
				// Fire new bullet
				if (kpm->GetDown() == false) // Only on key release
				{
					FireBullet();
				}
				break;
			case 71: // G
				if (kpm->GetDown() == false) // Only on key release
				{
					Message msg("godmode");
					_owner->OnMessage(&msg);
				}
				break;
		}
	}
}

/******************************************************************************************************************/

// Shutdown function -- called when owner object is destroyed
void ShipControllerComponent::End()
{
	_owner->UnregisterListener("keypress", this);
}

/******************************************************************************************************************/

void ShipControllerComponent::TurnLeft(float angle)
{
	float currentAngle = _owner->GetAngle();
	currentAngle -= angle;
	if (currentAngle < 0) currentAngle += 360;
	_owner->SetAngle(currentAngle);
}

/******************************************************************************************************************/

void ShipControllerComponent::TurnRight(float angle)
{
	float currentAngle = _owner->GetAngle();
	currentAngle += angle;
	if (currentAngle > 360) currentAngle -= 360;
	_owner->SetAngle(currentAngle);
}

/******************************************************************************************************************/

void ShipControllerComponent::Accelerate(float amt)
{
	Vector4 thrust(0, amt, 0, 0);
	thrust.rotate(_owner->GetAngle());
	
	// Create thrust message and send to owner object
	ThrustMessage msg(thrust);
	_owner->OnMessage(&msg);
}

/******************************************************************************************************************/

void ShipControllerComponent::FireBullet()
{
	for (int i = 0; i < NUM_BULLETS; i++)
	{
		if (_bullets[i]->IsAlive() == false)
		{
			// Use this bullet
			_bullets[i]->Spawn(_owner->GetPosition(), _owner->GetAngle());
			return;
		}
	}
}

/******************************************************************************************************************/

void ShipControllerComponent::Reset()
{
	_turnLeftPressed = false;
	_turnRightPressed = false;
	_acceleratePressed = false;
}

/******************************************************************************************************************/
