#include <Editor/Editor.h>
#include <Nodes/DemoNode.h>
#include <Editor/NodeFactory.h>

NEDIT_INTERNAL_NAMESPACE_START();


void Editor::Render(float delta)
{
    auto& io = ImGui::GetIO();

    //ImGui::Text("FPS: %.2f (%.2gms)", io.Framerate, io.Framerate ? 1000.0f / io.Framerate : 0.0f);

    //ImGui::Separator();

    NodeEditor::SetCurrentEditor(m_Context);
    NodeEditor::Begin("My Editor", ImVec2(GetWidth(), GetHeight()));
    
    DrawNodes();

    NodeEditor::End();
    NodeEditor::SetCurrentEditor(nullptr);
    
}

void Editor::Process(float delta)
{

}

void Editor::Shutdown()
{
    NodeEditor::DestroyEditor(m_Context);
}

void Editor::SetupApp()
{
    
    NodeEditor::Config config;
    config.SettingsFile = "Simple.json";
    m_Context = NodeEditor::CreateEditor(&config);

    m_Nodes.push_back(NodeFactory::CreateNode<NEdit::DemoNode>());
    m_Nodes.push_back(NodeFactory::CreateNode<NEdit::DemoNode>());
    m_Nodes.push_back(NodeFactory::CreateNode<NEdit::DemoNode>());
    m_Nodes.push_back(NodeFactory::CreateNode<NEdit::DemoNode>());
    m_Nodes.push_back(NodeFactory::CreateNode<NEdit::DemoNode>());
    m_Nodes.push_back(NodeFactory::CreateNode<NEdit::DemoNode>());

}

void Editor::DrawNodes()
{
    for (BaseNode node : m_Nodes)
    {
        DrawNode(node);
    }
}

void Editor::DrawNode(BaseNode& node)
{

    
    BeginNode(node.GetId());

    ImGui::Text(node.GetTitle());
    DrawPins(node);

    EndNode();
   
    // Start drawing nodes.
    
    
}

void Editor::DrawPins(BaseNode& node)
{
    for(Pin pin : node.GetPinIns())
    {
        DrawPin(pin, PinKind::Input);
    }

    ImGui::SameLine();

    for (Pin pin : node.GetPinOuts())
    {
        DrawPin(pin, PinKind::Output);
    }
}

void Editor::DrawPin(Pin& pin, PinKind type)
{
    BeginPin(pin.GetId(), type);
    ImGui::Text(pin.GetLabel());
    EndPin();
}


NEDIT_NAMESPACE_END();