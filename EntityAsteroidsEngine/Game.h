#pragma once
#include <time.h>
#include <map>
#include <vector>

// Systems
#include "PhysicsSystem.h"
#include "RenderSystem.h"
#include "CollisionSystem.h"

#include "SceneManager.h"
#include "ResourceManager.h"
// Forward declarations
class GameObject;
class Message;
class Renderer;
class Window;




// Generic game class
class Game
{
	// "Singleton"
public:
	static Game* TheGame;

	// Data
protected:
	double							_currentTime;		// Current time for delta time purposes
	double							_deltaTime;			// Time since last frame
	bool							_keyStates[256];	// Keyboard status
	bool							_quitFlag;			// Quit flag; when true, we quit
	Renderer*						_renderer;			// The renderer
	Window*							_window;			// The game window

	// Systems
	RenderSystem					_renderSystem;		// To handle rendering

	// Scene Manager
	SceneManager					_sceneManager;

	// Structors
public:
	Game();
	virtual ~Game();


	// Gets/sets
public:


	// Quit flag
	bool GetQuitFlag()						const	{ return _quitFlag; }
	void SetQuitFlag(bool v)						{ _quitFlag = v; }

	// Renderer
	Renderer* GetRenderer()					const	{ return _renderer; }

	// Functions
public:
	void AddGameObject(GameObject* obj)				{ _sceneManager.AddGameObject(obj); }
	std::vector<GameObject*>& GetGameObjects()		{ return _sceneManager.GetGameObjects(); }

	// Initialise game
	virtual void Initialise(Window* w);

	// Keyboard input
	virtual void OnKeyboard(int key, bool down);

	// Draw everything
	virtual void Render() = 0;

	// Main game loop (update)
	virtual void Run();

	// Message system
	void BroadcastMessage(Message* msg);

	// The game can respond to messages too
	virtual void ListenToMessage(Message* msg)		{}
};
