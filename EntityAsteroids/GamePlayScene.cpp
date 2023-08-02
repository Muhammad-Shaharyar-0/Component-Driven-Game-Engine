#include "GamePlayScene.h"
#include "SceneManager.h"
#include "Game.h"
#include "RenderSystem.h"
#include "Asteroid.h"
#include "Message.h"
#include "Canvas.h"
#include "Voxel.h"
#include "ResourceManager.h"
#include "GUI.h"

using namespace Datastructers;
/******************************************************************************************************************/
// Structors
/******************************************************************************************************************/

GamePlayScene::GamePlayScene()
{

}

/******************************************************************************************************************/

GamePlayScene::~GamePlayScene()
{
}

/******************************************************************************************************************/
// Functions
/******************************************************************************************************************/

void GamePlayScene::Initialise()
{

	////////////////
	// Setup Objects

	// Create canvas
	_canvas = new Canvas(25);
	_gameObjects.push_back(_canvas);
	for (size_t i = 0; i < _canvas->_voxels.size() ; i++)
	{
		_gameObjects.push_back(_canvas->_voxels[i]);
	}
	_camera = new Camera();
	_camera->_camera->mWidth = Game::TheGame->Width();
	_camera->_camera->mHeight = Game::TheGame->Height();
	float aspectRatio = _camera->_camera->mWidth / _camera->_camera->mHeight;
	_camera->SetPosition(_camera->_camera->mEye);
	_camera->_camera->mView = LookAtLH(_camera->_camera->mEye, _camera->_camera->mLookAt, _camera->_camera->mUp);
	_camera->_camera->mProj = ProjectionLH(1.0472f, aspectRatio, _camera->_camera->mNear, _camera->_camera->mFar);
	_gameObjects.push_back(_camera);


	// Start all objects to set them up
	for (int i = 0; i < (int)_gameObjects.size(); i++)
	{
		_gameObjects[i]->Start();
	}
	ResourceManager::Instance()->_gameObjects = _gameObjects;
	GUI::GetInstance().AddIntVariable("Number of Player", 1);
	GUI::GetInstance().AddIntVariable("Voxels", _canvas->_voxels.size());
	GUI::GetInstance().AddIntVariable("Total Mass", _canvas->_voxels.size());
	GUI::GetInstance().AddIntVariable("Total Mass PCS", _canvas->_voxels.size());


}

/******************************************************************************************************************/

void GamePlayScene::OnKeyboard(int key, bool down)
{

	if (down) return; // Ignore key down events

	// Switch key presses
	switch (key)
	{

	case 82: // R
		Reset();
		break;

	}
}

/******************************************************************************************************************/

/// Update current scene
void GamePlayScene::Update(double deltaTime)
{
	Scene::Update(deltaTime);
	mInputManager->Update();
	if (mInputManager->KeyHeld(KEY::KEY_R))
	{
		Reset();
	}


	_physicsSystem.Process(_gameObjects, deltaTime);
	_collisionSystem.Process(_gameObjects, deltaTime);

	// Perform legacy update on game objects (in theory, should be phased out altogether)
	for (int i = 0; i < (int)_gameObjects.size(); i++)
	{
		if (_gameObjects[i]->IsAlive())
		{
			_gameObjects[i]->Update(deltaTime);
		}
	}


	//Left click to cast ray at mouse position
	if (mInputManager->KeyHeld(KEY::MOUSE_BUTTON_LEFT))
	{
		const Vector4 dir = mInputManager->MouseWorld(_camera->_camera->mView, _camera->_camera->mProj, _camera->_camera->mWidth, _camera->_camera->mHeight);
		/*mRayID = mEcsManager->CreateEntity();
		const RayCollider ray{ mEye, dir };
		mEcsManager->AddRayColliderComp(ray, mRayID);*/
		GameObject* Ray = new GameObject("Ray");
		Ray->SetAlive(true);
		//Ray->AddComponent(new RayColliderComponent(Ray, _camera->_camera->mEye, dir));
		RayColliderComponent* rc = new RayColliderComponent(Ray, _camera->_camera->mEye, dir);
		rc->SetCollisionID(CollisionID::Ray);
		rc->SetCollisionMatrixFlag(CollisionID::VoxelCollider);
		Ray->AddComponent(rc);
		_gameObjects.push_back(Ray);
	}
	
}

/******************************************************************************************************************/

/// Render current scene
void GamePlayScene::Render(RenderSystem* renderer)
{
	if (_camera->_camera->isCameraChanged)
	{
		_camera->_camera->isCameraChanged = false;
		renderer->SetCamera(_camera->_camera);
	}
	renderer->Process(_gameObjects,0);

}

/******************************************************************************************************************/

void GamePlayScene::Reset()
{
	//int numAsteroidsFound = 0;
	//_minAsteroids = NUM_ASTEROIDS;

	//for (int i = 0; i < (int)_gameObjects.size(); i++)
	//{
	//	// Delete excess asteroids
	//	if (_gameObjects[i]->GetType() == "Voxel")
	//	{
	//		numAsteroidsFound++;
	//		if (numAsteroidsFound > _minAsteroids)
	//		{
	//			delete _gameObjects[i];
	//			_gameObjects.erase(_gameObjects.begin() + i);
	//			i--;
	//			continue;
	//		}
	//	}

	//	// Reset
	//	_gameObjects[i]->Reset();
	//}

	for each (Voxel* var in _canvas->_voxels)
	{
		var->Reset();
	}
	_camera->_camera->mWidth = Game::TheGame->Width();
	_camera->_camera->mHeight = Game::TheGame->Height();
	float aspectRatio = _camera->_camera->mWidth / _camera->_camera->mHeight;
	_camera->SetPosition(_camera->_camera->mEye);
	_camera->_camera->mView = LookAtLH(_camera->_camera->mEye, _camera->_camera->mLookAt, _camera->_camera->mUp);
	_camera->_camera->mProj = ProjectionLH(1.0472f, aspectRatio, _camera->_camera->mNear, _camera->_camera->mFar);
	_camera->_camera->isCameraChanged = true;



}

/******************************************************************************************************************/
