#pragma once
#include <map>
#include <vector>
#include "Transform.h"
#include "Vector4.h"
#include "MathsHelper.h"
#include <string>

// Forward references
class GameObjectComponent;
class Message;


// Typedefs
typedef std::map<std::string, GameObjectComponent*> ComponentMap;
typedef std::map<std::string, GameObjectComponent*>::iterator ComponentMapIterator;
typedef std::map<std::string, std::vector<GameObjectComponent*> > MessageListenerMap;
typedef std::map<std::string, std::vector<GameObjectComponent*> >::iterator MessageListenerMapIterator;
typedef std::vector<GameObjectComponent*>::iterator ComponentListIterator;


// Now new and improved to use a component-based architecture
class GameObject
{
	// Constants
public:


	// Data
protected:
	std::string			_type;			// Type of the object
	Transform			transform;
	bool				_isCanvas=false;			// Alive flag; when false, is not updated
	bool				_deleteFlag;	// Set when you want this game object to be deleted by the game
	bool _alive;
	// Components
	ComponentMap		_components;

	// Listener registration
	MessageListenerMap	_messageListeners;



	// Constructors
public:
	GameObject(std::string type);
	virtual ~GameObject();

	// Disable copy constructor + assignment operator
private:
	GameObject(const GameObject&);
	GameObject& operator=(const GameObject&);


	// Gets/sets
public:
	Datastructers::Vector4 GetAngle()													const	{ return transform.mRotation; }
	void SetAngle(Datastructers::Vector4 v)														{ transform.mRotation = v;  }

	Datastructers::Vector4 GetScale()													const	{ return transform.mScale; }
	void SetScale(Datastructers::Vector4 v)														{ transform.mScale = v; }

	Datastructers::Vector4 GetPosition()												const	{ return transform.mTranslation; }
	void SetPosition(Datastructers::Vector4 v)													{ transform.mTranslation = v; }

	bool IsAlive()														const	{ return _alive; }
	void SetAlive(bool v)														{ _alive = v; }

	bool ShouldBeDeleted()												const	{ return _deleteFlag; }
	void SetDeleteFlag(bool v)													{ _deleteFlag = v; }

	std::string GetType()												const	{ return _type; }

	// Component Functions
public:
	bool AddComponent(GameObjectComponent* goc)									;
	bool RemoveComponent(GameObjectComponent* goc)								;
	bool RemoveComponent(std::string componentType)								;
	GameObjectComponent* GetComponent(std::string type)							;

	void RegisterListener(std::string msg, GameObjectComponent* goc)			;
	void UnregisterListener(std::string msg, GameObjectComponent* goc)			;


	// General Functions
public:
	// Setup function -- called to initialise object and its components. Should only be called once
	virtual void Start();

	// Main update function (called every frame)
	virtual void Update(double deltaTime);

	// Message handler (called when message occurs)
	virtual void OnMessage(Message* msg);

	// Shutdown function -- called when object is destroyed (i.e., from destructor)
	virtual void End();

	// Resets the game object to the start state (similar to Start(), but may be called more than once)
	virtual void Reset();
};

