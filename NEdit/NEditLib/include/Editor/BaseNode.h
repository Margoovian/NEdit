#pragma once
#include <vector>
#include <Utility/Utility.h>
#include <Utility/Defines.h>
#include <Utility/Types.h>
#include <imgui_node_editor.h>
#include <Editor/Pin.h>

NEDIT_INTERNAL_NAMESPACE_START();

typedef std::vector<PinPropertyPacket> PinInArray;
typedef std::vector<PinPropertyPacket> PinOutArray;

class NodeFactory;

struct BaseNodePinPacket {
	PinInArray PinIns;
	PinOutArray PinOuts;
};

struct BaseNodePropertyPacket {
	const char* NodeTitle;
	Colour NodeColour;
	Vec2 NodeSize;
};

struct BaseNodeConstructionPacket {
	BaseNodePinPacket PinProperties;
	BaseNodePropertyPacket NodeProperties;
};

NEDIT_NAMESPACE_END();


NEDIT_NAMESPACE_START();

using namespace ax::NodeEditor;

class BaseNode {

	friend class Internal::NodeFactory;

public:
	inline const char* GetTitle() { return m_Title; }
	inline std::vector<Pin>& GetPinIns() { return m_Inputs; }
	inline std::vector<Pin>& GetPinOuts() { return m_Outputs; }
	inline const Colour GetColour() { return m_Colour; }
	inline const Vec2 GetSize() { return m_Size; }
	inline unsigned int GetId() { return m_Id.Get(); }

protected:
	virtual Internal::BaseNodeConstructionPacket Construct() {
		static_assert(true, "Non-overridden construction of node, please override node construction.");
		return {};
	};

private:
	Internal::BaseNodeConstructionPacket Create() { return Construct(); };

private:
	NodeId m_Id;

	const char* m_Title;
	std::vector<Pin> m_Inputs;
	std::vector<Pin> m_Outputs;
	Colour m_Colour;
	Vec2 m_Size;

};

NEDIT_NAMESPACE_END_WITH_TYPE_DEFINES(BaseNode, Node);


NEDIT_INTERNAL_NAMESPACE_START();

template<typename T>
concept NodeType = std::is_base_of<class BaseNode, T>::value;

NEDIT_NAMESPACE_END();