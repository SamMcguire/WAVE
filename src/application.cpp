#include "application.h"
#include "events/application_event.h"
#include "log.h"


namespace Wave 
{
    Application::Application()
    {
    }

    Application::~Application()
    {
    }

    void Application::Run()
    {
        WindowResizeEvent e(1280, 720);
        TRACE("{0}", e.ToString());
    }
}