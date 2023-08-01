#include "RenderSystem.h"
#include "GameObject.h"
#include "RenderComponent.h"
#include "ThreadManager.h"

/******************************************************************************************************************/
// Structors
/******************************************************************************************************************/

RenderSystem::RenderSystem()
	: _renderer(NULL)
{
	
}

/******************************************************************************************************************/

RenderSystem::~RenderSystem()
{
}

/******************************************************************************************************************/
// Functions
/******************************************************************************************************************/

void RenderSystem::SetCamera(CameraComponent* camera)
{
	_renderer->SetViewProj(camera);
}

void RenderSystem::Process(std::vector<GameObject*>& list, double deltaTime)
{
	if (_renderer == NULL) return;
	for (GameObject* obj : list)
	{
		if (obj->IsAlive())
		{
			if (RenderComponent* rc = (RenderComponent*)obj->GetComponent("render"))
			{
				_renderer->Draw(rc, _MVM);
			}
		}
	}

}

/******************************************************************************************************************/
