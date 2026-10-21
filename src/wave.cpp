#include "pch.h"
#include <spdlog/spdlog.h>
#include "log.h"
#include "application.h"
#include "events/event.h"

int main()
{
	Wave::Log::Init();
	Wave::Application app;
	app.Run();
	// Wave::Log::Init();
	// std::cout << "Hello Nebula peeps!" << std::endl;
	// INFO("Hello from Wave!");
    // WARN("This is a Warning!");
	return 0;
}