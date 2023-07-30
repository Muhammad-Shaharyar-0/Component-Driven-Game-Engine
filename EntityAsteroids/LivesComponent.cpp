#include "LivesComponent.h"
#include "GameObject.h"
#include "Game.h"
#include "DeadObjectMessage.h"
#include "DamageMessage.h"

/******************************************************************************************************************/
// Structors
/******************************************************************************************************************/

LivesComponent::LivesComponent(GameObject* gob)
	: GameObjectComponent("lives", gob), _livesRemaining(5)
{

}

/******************************************************************************************************************/

LivesComponent::~LivesComponent()
{
}

/******************************************************************************************************************/
// Functions
/******************************************************************************************************************/

// Setup function -- called when owner object is initialised (using its own Start method)
void LivesComponent::Start()
{
	// Register for damage event
	_owner->RegisterListener("damage", this);
}

/******************************************************************************************************************/

// Main update function (called every frame)
void LivesComponent::Update(double deltaTime)
{
}

/******************************************************************************************************************/

// Message handler (called when message occurs)
void LivesComponent::OnMessage(Message* msg)
{
  	if (msg->GetMessageType() == "damage")
	{
		DamageMessage* dMsg = (DamageMessage*)msg;
		_livesRemaining-=dMsg->GetDamage();
		if (_livesRemaining <= 0)
		{
			// Send out death message
  			DeadObjectMessage dom(_owner);
			_owner->OnMessage(&dom);
		}
	}
}

/******************************************************************************************************************/

void LivesComponent::SetLives(int lives)
{
	_livesRemaining = lives;
}

/******************************************************************************************************************/

// Shutdown function -- called when owner object is destroyed
void LivesComponent::End()
{
	_owner->UnregisterListener("damage", this);
}

/******************************************************************************************************************/
