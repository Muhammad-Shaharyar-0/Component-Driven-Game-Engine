#pragma once
#include "Vector4.h"

struct Colour
{
	//rgba
	Datastructers::Vector4 mColour;

	Colour(float x,float y,float z,float w)
	{
		mColour.X = x;
		mColour.Y = y;
		mColour.Z= z;
		mColour.W = w;
	}
	Colour& operator+=(const Colour& rhs);
	Colour& operator-=(const Colour& rhs);
};

inline Colour operator+(Colour lhs, const Colour& rhs) { lhs += rhs; return lhs; }
inline Colour operator-(Colour lhs, const Colour& rhs) { lhs -= rhs;	return lhs; }

