#pragma once

#include <memory>
#include <SDL.h>
#include <imgui.h>

#include <Core.h>

#include <Defines.h>

NEDIT_INTERNAL_NAMESPACE_START

struct NEDIT_API WindowContext {
	int Width, Height;
	const char* Title;
	uint32_t Flags;
	struct Colour { float r, g, b, a; } BackgroundColour;
};


class NEDIT_API Window {

public:

	Window(const WindowContext Context);

	void Start();

protected:
	void virtual Render() = 0;
	void virtual Process() = 0;
	void virtual Shutdown() = 0;
	void virtual SetupApp() = 0;

	const int GetWidth() const;
	const int GetHeight() const;
	const ImVec2 GetSize() const;
	const ImVec2 GetWindowPosition() const;


private:

	SDL_Window* GetWindow() const;
	SDL_Renderer* GetRenderer() const;

	void Initialize();
	void CreateWindow(const WindowContext& Context);
	void SetupContexts();
	void FinalizeSetup();

private:
	void Exit();
	void RenderInternal();
	bool ProcessInternal();

private:
	SDL_Window* m_Window;
	SDL_Renderer* m_Renderer;

	bool m_Running = false;
	WindowContext m_WindowContext;

};

NEDIT_NAMESPACE_END