#include <iostream>
#include <spdlog/spdlog.h>
#include "log.h"

int main()
{
	Wave::Log::Init();
	std::cout << "Hello Nebula peeps!" << std::endl;
	INFO("Hello from Wave!");
    WARN("This is a Warning!");
	return 0;
}