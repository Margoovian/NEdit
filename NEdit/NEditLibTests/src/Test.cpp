#include <Test.h>
#include <Editor/Editor.h>
#include <iostream>

int main()
{

	uint32_t Flags = 32 | 8; // 32 -> SDL_WINDOW_RESIZABLE | 8 -> SDL_WINDOW_HIDDEN

	std::cout << "Hello World\n";

	NEdit::Internal::Editor editor({ 1280, 720, "Editor", Flags, { 15,15,20,255 } });
	editor.Start();

	return 0;

}