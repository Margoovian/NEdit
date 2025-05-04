#pragma once

#include <vector>

#include <Core/Window.h>
#include <Editor/BaseNode.h>
#include <Editor/Link.h>
#include <imgui_node_editor.h>

NEDIT_INTERNAL_NAMESPACE_START();

using namespace ax;

class NEDIT_API Editor : public Window {


public:

	Editor(const WindowContext Context) : Window(Context) {};

protected:
	void virtual Render(float deltaTime) override;
	void virtual Process(float deltaTime) override;
	void virtual Shutdown() override;
	void virtual SetupApp() override;

private:
	void DrawNodes();
	void DrawNode(BaseNode& node);
	void DrawPins(BaseNode& node);
	void DrawPin(Pin& pin, PinKind type);

private:
	NodeEditor::EditorContext* m_Context = nullptr;

	std::vector<BaseNode> m_Nodes;
	std::vector<Link> m_Links;
};

NEDIT_NAMESPACE_END();