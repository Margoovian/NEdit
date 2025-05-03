#pragma once
#include <Core/Window.h>

NEDIT_INTERNAL_NAMESPACE_START


class NEDIT_API Editor : public Window {
public:

	Editor(const WindowContext Context) : Window(Context) {};

protected:
	void virtual Render() override;
	void virtual Process() override;
	void virtual Shutdown() override;
	void virtual SetupApp() override;
};

NEDIT_NAMESPACE_END