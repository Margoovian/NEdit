#pragma once

#include <string>
#include <Utility/Defines.h>
#include <Utility/Types.h>
#include <imgui_node_editor.h>


NEDIT_INTERNAL_NAMESPACE_START();

class NodeFactory;

struct PinPropertyPacket  {
	const char* PinLabel;
	Colour PinColour;
};

NEDIT_NAMESPACE_END();

NEDIT_NAMESPACE_START();

using namespace ax::NodeEditor;

class Pin {

	friend class Internal::NodeFactory;

public:
	inline const char* GetLabel() const { return m_Label.c_str(); }
	inline const Colour GetColour() const { return m_Colour; }
	inline unsigned int GetId() { return m_Id.Get(); }

private:
	PinId m_Id;
	std::string m_Label;
	Colour m_Colour;

};

NEDIT_NAMESPACE_END_WITH_TYPE_DEFINES(Pin, Pin);