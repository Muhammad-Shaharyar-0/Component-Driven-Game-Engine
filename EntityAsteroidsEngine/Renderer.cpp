#include "Renderer.h"
#include "RenderComponent.h"

/******************************************************************************************************************/

Renderer::Renderer(): _clearColour(0,0,0,1)
{
	
}

/******************************************************************************************************************/

Renderer::~Renderer()
{
}

/******************************************************************************************************************/

void Renderer::Draw(RenderComponent* rc, glm::mat4 MVM)
{
	if (rc->ShouldDraw())
	{
		MVM = glm::translate(MVM, glm::vec3(rc->GetPosition().X, rc->GetPosition().Y, 0));
		MVM = glm::rotate(MVM, -rc->GetAngle().Magnitude(), glm::vec3(0, 0, 1)); // Rotates anti-clockwise
		MVM = glm::scale(MVM, glm::vec3(rc->GetScale().X, rc->GetScale().Y, 1));

		if (rc->GetMesh())
		{
			Draw(rc->GetMesh(), MVM, rc->GetColour());
		}
	}
}

/******************************************************************************************************************/
