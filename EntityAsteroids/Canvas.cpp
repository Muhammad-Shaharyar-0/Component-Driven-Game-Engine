#include "Canvas.h"
#include "ResourceManager.h"
#include "Components.h"
Canvas::Canvas(int _size) : GameObject("Canvas")
{
	size = _size;
	float y = -10;
	for (size_t i = 0; i < size; i++)
	{
		float x = -10;
		for (size_t j = 0; j < size; j++)
		{
			
			Voxel* _voxel = new Voxel(ResourceManager::Instance()->GetMesh("ship"));
			_voxels.push_back(_voxel);
			_voxel->SetPosition(Datastructers::Vector4(x, y, 0.0f, 1.0f));
			_voxel->SetScale(Datastructers::Vector4(.5, .5, .5, .5));
			_voxel->SetTransform(Datastructers::TranslationMatrix(_voxel->GetPosition()) * Datastructers::ScaleMatrix(_voxel->GetScale()));
			_voxel->setBounds();
			x = x + 1.1;
		}
		y = y + 1.1;
	}

	_alive = true;

	RenderComponent* rc = new RenderComponent(this);
	rc->ShouldDraw(true);
	_alive = true;
	_isCanvas = true;
}

Canvas::~Canvas()
{
}

void Canvas::Update(double deltaTime)
{
	GameObject::Update(deltaTime);
}
