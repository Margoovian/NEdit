#pragma once
#include <vector>
#include <array>
#include <memory>
#include <Utility/Defines.h>
#include <Editor/BaseNode.h>


NEDIT_INTERNAL_NAMESPACE_START();

class NodeFactory {

public:

	template<NodeType UserNode>
	static NEdit::BaseNode CreateNode() {

		static unsigned int uniqueId;

		uniqueId++;

		UserNode node;
		BaseNodeConstructionPacket properties = node.Create();
		
		BaseNode& nodeBase = node;

		nodeBase.m_Id = uniqueId;
		nodeBase.m_Title = properties.NodeProperties.NodeTitle;
		nodeBase.m_Colour = properties.NodeProperties.NodeColour;
		nodeBase.m_Size = properties.NodeProperties.NodeSize;

		for (PinPropertyPacket in : properties.PinProperties.PinIns) {

			uniqueId++;

			Pin newPin;
			newPin.m_Id = uniqueId;
			newPin.m_Label = in.PinLabel;
			newPin.m_Colour = in.PinColour;

			nodeBase.m_Inputs.emplace_back(std::move(newPin));
		}

		for (PinPropertyPacket out : properties.PinProperties.PinOuts) {

			uniqueId++;

			Pin newPin;
			newPin.m_Id = uniqueId;
			newPin.m_Label = out.PinLabel;
			newPin.m_Colour = out.PinColour;

			nodeBase.m_Outputs.emplace_back(std::move(newPin));

		}

		return nodeBase;

	}

};

NEDIT_NAMESPACE_END();