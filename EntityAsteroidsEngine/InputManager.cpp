#include "InputManager.h"
#include <algorithm>

using namespace Datastructers;

InputManager::InputManager()
{
}

Vector4 InputManager::MouseWorld(const Matrix4x4& pView, const Matrix4x4& pProj, const float& pWidth, const float& pHeight) const
{
	// Calculate the inverse view-projection matrix
	Matrix4x4 invViewProj = Inverse(pView * pProj);

	// Calculate the normalized device coordinates (NDC) of the mouse position
	float ndcX = (2.0f * mMousePosition.X) / pWidth - 1.0f;
	float ndcY = 1.0f - (2.0f * mMousePosition.Y) / pHeight;

	// Construct the mouse position in NDC space
	Vector4 mousePosNDC(ndcX, ndcY, 1.0f, 1.0f);

	// Transform the mouse position from NDC space to world space
	Vector4 mouseWorld = mousePosNDC * invViewProj;

	// Set the Z and W components of the mouseWorld vector
	mouseWorld.Z = 1.0f;
	mouseWorld.W = 0.0f;

	// Normalize the mouseWorld vector
	mouseWorld.Normalise();

	return mouseWorld;
}

InputManager::~InputManager()
{
}

bool InputManager::KeyDown(const KEY& pButton)
{
	const auto key = std::find_if(mKeyPresses.begin(), mKeyPresses.end(),
		[&](const std::pair<KEY, KEY_STATE>& pKeyDown) {return pKeyDown.first == pButton && pKeyDown.second == KEY_STATE::KEY_DOWN; });

	return (key != mKeyPresses.end());
}

bool InputManager::KeyUp(const KEY& pButton)
{
	const auto key = std::find_if(mKeyPresses.begin(), mKeyPresses.end(),
		[&](const std::pair<KEY, KEY_STATE>& pKeyDown) {return pKeyDown.first == pButton && pKeyDown.second == KEY_STATE::KEY_UP; });

	return (key != mKeyPresses.end());
}

bool InputManager::KeyHeld(const KEY& pButton)
{
	const auto key = std::find_if(mKeyPresses.begin(), mKeyPresses.end(),
		[&](const std::pair<KEY, KEY_STATE>& pKeyDown) {return pKeyDown.first == pButton && pKeyDown.second == KEY_STATE::KEY_HELD; });

	return (key != mKeyPresses.end());
}
