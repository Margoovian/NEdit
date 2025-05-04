#pragma once

#include <memory>
#include <SDL.h>
#include <imgui.h>

#include <Core.h>

#include <Utility/Defines.h>
#include <Utility/Types.h>

NEDIT_INTERNAL_NAMESPACE_START();

struct NEDIT_API WindowContext {
	int Width, Height;
	const char* Title;
	uint32_t Flags;
	Colour BackgroundColour;
};

struct NEDIT_API TimeRecord {

	float Delta() {
		return DeltaRecord;
	};

	void Tick() {
		LastRecord = CurrentRecord;
		CurrentRecord = (float)SDL_GetPerformanceCounter();
		DeltaRecord = (CurrentRecord - LastRecord) * 1000 / SDL_GetPerformanceFrequency();
	};

private:
	float LastRecord = 0.0f;
	float CurrentRecord = 0.0f;
	float DeltaRecord = 0.0f;

};

class NEDIT_API Window {

public:

	Window(const WindowContext Context);

	void Start();

protected:
	void virtual Render(float deltaTime) = 0;
	void virtual Process(float deltaTime) = 0;
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
	SDL_Window* m_Window = nullptr;
	SDL_Renderer* m_Renderer = nullptr;

	bool m_Running = false;
	WindowContext m_WindowContext;

	TimeRecord m_DeltaTime;

};

NEDIT_NAMESPACE_END();