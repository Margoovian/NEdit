#pragma once
#include <Utility/Defines.h>
#include <imgui.h>

NEDIT_NAMESPACE_START();

typedef ImVec2 Vec2;
typedef ImVec4 Vec4;

struct Colour {

	float r, g, b, a;

	operator Vec4() const { return Vec4(r, g, b, a); }

};

NEDIT_NAMESPACE_END();