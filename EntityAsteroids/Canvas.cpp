#include "Canvas.h"
#include "ResourceManager.h"
#include "Components.h"
Canvas::Canvas(int _size) : GameObject("Canvas")
{
	size = _size;
	float y = -0.5;
	for (size_t i = 0; i < size; i++)
	{
		float x = -0.5;
		for (size_t j = 0; j < size; j++)
		{
			
			Voxel* _voxel = new Voxel(ResourceManager::Instance()->GetMesh("ship"));
			_voxels.push_back(_voxel);
			_voxel->SetPosition(Vector4(x, y, 0.0f, 1.0f));
			x = x + 0.021;
		}
		y = y + 0.021;
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
}
