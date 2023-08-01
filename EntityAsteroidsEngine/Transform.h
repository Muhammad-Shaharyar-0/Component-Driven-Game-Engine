#pragma once
#include "Vector4.h"
#include "Matrix4x4.h"
#include "MatrixMath.h"

struct Transform
{
	Datastructers::Matrix4x4 mTransform = Datastructers::TranslationMatrix(mTranslation)* Datastructers::ScaleMatrix(Datastructers::Vector4(.1, .1, .1, 1.0f));
	Datastructers::Vector4 mTranslation = Datastructers::Vector4(0, 0, 0, 1.0f);
	Datastructers::Vector4 mRotation = Datastructers::Vector4(0, 0, 0, 1.0f);
	Datastructers::Vector4 mScale = Datastructers::Vector4(0.1, 0.1, 0.1, 1.0f);
	Datastructers::Vector4 mForward;
	Datastructers::Vector4 mRight;
	Datastructers::Vector4 mUp;
};