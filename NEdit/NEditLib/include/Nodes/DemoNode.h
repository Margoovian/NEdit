#pragma once

#include <Utility/Defines.h>
#include <Editor/BaseNode.h>

NEDIT_NAMESPACE_START();

class DemoNode : public BaseNode {

protected:
	Internal::BaseNodeConstructionPacket Construct() override
	{
		return {

			{
				Internal::PinInArray(
					{
						{
							"In",
							{0,255,0,255}
						}
					}
				),

				Internal::PinOutArray(
					{
						{
							"Out",
							{0,0,255,255}
						}
					}
				)

			},
			{
				"Demo Node",
				{255,0,0,255},
				{200,200}
			}

		};
	}

};

NEDIT_NAMESPACE_END();