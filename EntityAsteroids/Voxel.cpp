#include "Voxel.h"
#include "CollisionMatrix.h"
#include "CollisionMessage.h"

#include "DeadObjectMessage.h"
#include "Game.h"
#include <algorithm>

template <typename T>
const T& clamp(const T& value, const T& minValue, const T& maxValue)
{
	return value < minValue ? minValue : (value > maxValue ? maxValue : value);
}

/******************************************************************************************************************/

Voxel::Voxel(Mesh* mesh)
	: GameObject("Voxel")
{
	// Create components for Ship (they will add themselves)
	//new ShipControllerComponent(this);
	//new GodModeComponent(this);
	//new ExplodableComponent(this);

	//PhysicsComponent* pc = new PhysicsComponent(this);
	//pc->SetMaxSpeed(MAX_SPEED);

	cc = new BoxColliderComponent(this);
	cc->SetCollisionID(CollisionID::VoxelCollider);
	cc->SetCollisionMatrixFlag(CollisionID::Ray);
	initialcolor = color;
	initialmass = mass;
	//VoxelCollisionDetectionComponent* Cd = new VoxelCollisionDetectionComponent(this);
	
	rc = new RenderComponent(this);
	rc->SetColour(color);
	rc->SetMesh(mesh);
	rc->ShouldDraw(true);
	_alive = true;
}

/******************************************************************************************************************/

Voxel::~Voxel()
{
}

void Voxel::setBounds()
{
	cc->setBounds(Datastructers::Vector3(transform.mTranslation.X - transform.mScale.X, transform.mTranslation.Y - transform.mScale.X, transform.mTranslation.Z - transform.mScale.X),
		Datastructers::Vector3(transform.mTranslation.X + transform.mScale.X, transform.mTranslation.Y + transform.mScale.X, transform.mTranslation.Z + transform.mScale.X));

}

/******************************************************************************************************************/

void Voxel::Update(double deltaTime)
{
	GameObject::Update(deltaTime);

	//// Cap speed
	//PhysicsComponent* physics = (PhysicsComponent*)GetComponent("physics");
	//physics->LimitToMaximumSpeed(MAX_SPEED);
}

/******************************************************************************************************************/

void Voxel::OnMessage(Message* msg)
{
	if (msg->GetMessageType() == "collision")
	{
		//CollisionMessage* col = (CollisionMessage*)msg;
		//if (col->GetCollidee() == this ||
		//	col->GetCollider() == this)
		//{
		//	RenderComponent* rc = (RenderComponent*)GetComponent("render");
		//	rc->ShouldDraw(false);
		//	_alive = false;

		//	// Send out death message
		//	DeadObjectMessage dom(this);
		//	OnMessage(&dom);

		//	// Change game state
		//	Message msg("state=dead");
		//	Game::TheGame->ListenToMessage(&msg);
		//}
			//rc->ShouldDraw(false);
			//_alive = false;
			mass++;
			color.mColour = LerpColors(color.mColour, stolencolor.mColour, 0.5);
			rc->SetColour(color);
	}

	GameObject::OnMessage(msg);
}

Datastructers::Vector4 Voxel::LerpColors(const Datastructers::Vector4& color1, const Datastructers::Vector4& color2, float weight)
{
	// Clamp the weight between 0 and 1 to ensure a valid lerp
	weight = clamp(weight, 0.0f, 1.0f);

	// Perform the linear interpolation between color1 and color2 using the weight
	return color1 + (color2 - color1) * weight;
}

/******************************************************************************************************************/

void Voxel::Reset()
{

	color = initialcolor;
	mass = initialmass;
	rc->SetColour(color);
	rc->ShouldDraw(true);
	_alive = true;
}

/******************************************************************************************************************/
