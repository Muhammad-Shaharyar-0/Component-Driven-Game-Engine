#pragma once
#include <memory>
#include <map>
#include <string>
#include <vector>

using namespace std;

class Mesh;
class GameObject;
typedef std::map<std::string, Mesh*> MeshMap;
typedef std::map<std::string, Mesh*>::iterator MeshMapIterator;

class ResourceManager
{


	//Private constructor for singleton pattern
	ResourceManager();

public:

	~ResourceManager();
	MeshMap							_meshes;			// The map of meshes
	std::vector<GameObject*>		_gameObjects;
	Mesh* GetMesh(std::string name);
	void AddMesh(std::string name, Mesh* mesh) { _meshes[name] = mesh; }

	//Singleton pattern
	//Deleted copy constructor and assignment operator so no copies of the singleton instance can be made
	ResourceManager(const ResourceManager& pResourceManager) = delete;
	ResourceManager& operator=(ResourceManager const&) = delete;

	static shared_ptr< ResourceManager > Instance();
};

inline Mesh* ResourceManager::GetMesh(std::string name)
{
	// Found
	MeshMapIterator i = _meshes.find(name);
	if (i != _meshes.end())
	{
		return i->second;
	}
	// Not found
	return NULL;
}