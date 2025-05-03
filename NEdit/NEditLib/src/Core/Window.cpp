#include <Core/Window.h>

#include <stdio.h>

#include <backends/imgui_impl_sdl.h>
#include <backends/imgui_impl_sdlrenderer.h>

NEDIT_INTERNAL_NAMESPACE_START

Window::Window(const WindowContext Context)
{

	Initialize();

	CreateWindow(Context);

	SetupContexts();

	FinalizeSetup();

	m_WindowContext = Context;

}

void Window::Start()
{

	SetupApp();

	m_Running = true;

	while (m_Running)
	{

		if (ProcessInternal())
		{
			continue;
		}

		RenderInternal();
	}

	Exit();

}

const int Window::GetWidth() const
{
	return ImGui::GetWindowWidth();
}

const int Window::GetHeight() const
{
	return ImGui::GetWindowHeight();
}

const ImVec2 Window::GetSize() const
{
	return ImGui::GetWindowSize();
}

const ImVec2 Window::GetWindowPosition() const
{
	return ImGui::GetWindowPos();
}

SDL_Window* Window::GetWindow() const
{
	return m_Window;
}

SDL_Renderer* Window::GetRenderer() const
{
	return m_Renderer;
}

void Window::Initialize()
{
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_GAMECONTROLLER) != 0)
	{
		printf("Error: %s\n", SDL_GetError());
		return;
	}
}

void Window::CreateWindow(const WindowContext& Context)
{
	// Setup window
	m_Window = SDL_CreateWindow(Context.Title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, Context.Width, Context.Height, Context.Flags);

	// Setup SDL_Renderer instance
	m_Renderer = SDL_CreateRenderer(GetWindow(), -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);

	if (GetRenderer() == NULL)
	{
		SDL_Log("Error creating SDL_Renderer!");
		return;
	}

	SDL_ShowWindow(GetWindow());
}

void Window::SetupContexts()
{
	// Setup Dear ImGui context
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	//io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
	//io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls

	// Setup Dear ImGui style
	ImGui::StyleColorsDark();
	//ImGui::StyleColorsLight();

	// Setup Platform/Renderer backends
	ImGui_ImplSDL2_InitForSDLRenderer(GetWindow(), GetRenderer());
	ImGui_ImplSDLRenderer_Init(GetRenderer());
}

void Window::FinalizeSetup()
{
}

void Window::Exit()
{

	// Cleanup
	ImGui_ImplSDLRenderer_Shutdown();
	ImGui_ImplSDL2_Shutdown();
	ImGui::DestroyContext();

	SDL_DestroyRenderer(GetRenderer());
	SDL_DestroyWindow(GetWindow());
	SDL_Quit();

}

void Window::RenderInternal()
{
	
	// Start the Dear ImGui frame
	ImGui_ImplSDLRenderer_NewFrame();
	ImGui_ImplSDL2_NewFrame();
	ImGui::NewFrame();

	Render();

	// Get ImGuiIO
	ImGuiIO& io = ImGui::GetIO();

	// Rendering
	ImGui::Render();
	SDL_RenderSetScale(GetRenderer(), io.DisplayFramebufferScale.x, io.DisplayFramebufferScale.y);
	SDL_SetRenderDrawColor(GetRenderer(),
		m_WindowContext.BackgroundColour.r,
		m_WindowContext.BackgroundColour.g,
		m_WindowContext.BackgroundColour.b,
		m_WindowContext.BackgroundColour.a
	);
	SDL_RenderClear(GetRenderer());
	ImGui_ImplSDLRenderer_RenderDrawData(ImGui::GetDrawData());
	SDL_RenderPresent(GetRenderer());
}

bool Window::ProcessInternal()
{
	// Poll and handle events (inputs, window resize, etc.)
		// You can read the io.WantCaptureMouse, io.WantCaptureKeyboard flags to tell if dear imgui wants to use your inputs.
		// - When io.WantCaptureMouse is true, do not dispatch mouse input data to your main application, or clear/overwrite your copy of the mouse data.
		// - When io.WantCaptureKeyboard is true, do not dispatch keyboard input data to your main application, or clear/overwrite your copy of the keyboard data.
		// Generally you may always pass all inputs to dear imgui, and hide them from your application based on those two flags.
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		ImGui_ImplSDL2_ProcessEvent(&event);
		if (event.type == SDL_QUIT)
			m_Running = false;
		if (event.type == SDL_WINDOWEVENT && event.window.event == SDL_WINDOWEVENT_CLOSE && event.window.windowID == SDL_GetWindowID(GetWindow()))
			m_Running = false;
	}
	
	Process();

	if (SDL_GetWindowFlags(GetWindow()) & SDL_WINDOW_MINIMIZED)
	{
	    SDL_Delay(10);
	    return true; // Should skip
	}

	return false; // Should continue

}

NEDIT_NAMESPACE_END