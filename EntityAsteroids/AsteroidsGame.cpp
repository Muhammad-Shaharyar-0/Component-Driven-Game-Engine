#include "AsteroidsGame.h"
#include "Components.h"
#include "Message.h"
#include "MultiMesh.h"
#include "GamePlayScene.h"
#include <sstream>

/******************************************************************************************************************/

AsteroidsGame::AsteroidsGame()
{
}

/******************************************************************************************************************/

AsteroidsGame::~AsteroidsGame()
{
}

/******************************************************************************************************************/

void AsteroidsGame::Initialise(Window* w)
{
	// Initialise parent
	Game::Initialise(w);

	//////////////
	// Setup Meshes
	Mesh* meshShip = new Mesh();
	meshShip->LoadFromFile("ShipMesh.txt");
	ResourceManager::Instance()->AddMesh("ship", meshShip);


	// Create VBOs
	for (MeshMapIterator i = ResourceManager::Instance()->_meshes.begin();
		i != ResourceManager::Instance()->_meshes.end();
		++i)
	{
		i->second->CreateVBO(_renderer);
	}

	_sceneManager.PushScene(new GamePlayScene());
}

/******************************************************************************************************************/

void AsteroidsGame::OnKeyboard(int key, bool down)
{
	Game::OnKeyboard(key, down);

	_sceneManager.OnKeyboard(key, down);

	//if (down) return; // Ignore key down events

	//// Switch key presses
	//switch (key)
	//{
	//case 80: // P
	//	if (_gameState == Playing)
	//	{
	//		_gameState = Paused;
	//	}
	//	else if (_gameState = Paused)
	//	{
	//		_gameState = Playing;
	//	}
	//	break;
	//case 82: // R
	//	Reset();
	//	break;
	//case 85: // U
	//	_ufoTimer = 0;
	//	break;
	//case 27: // Escape
	//	SetQuitFlag(true);
	//	break;
	//}
}

/******************************************************************************************************************/

void AsteroidsGame::Render()
{
	// Clear screen
	_renderer->ClearScreen();

	//// Add this code for 3D (need to change ScoreDisplay to fit inside 3D window)
	//glm::mat4 MVM;
	//MVM = glm::perspectiveFov(45.0f, (float)_window->_width, (float)_window->_height, 0.1f, 100.0f);
	//MVM *= glm::lookAt(glm::vec3(0.0f, 0.0f, 2.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	//_renderSystem.SetMVM(MVM);

	_sceneManager.Render(&_renderSystem);

	// Swap buffers
	_renderer->SwapBuffers();
}

/******************************************************************************************************************/

void AsteroidsGame::Run()
{
	// Run parent method to get delta time etc
	Game::Run();

	// Update scenes
	_sceneManager.Update(_deltaTime);

	// Check for exit
	if (_sceneManager.GetCurrentScene() == NULL)
	{
		SetQuitFlag(true);
	}

	// Draw
	Render();
}

/******************************************************************************************************************/
