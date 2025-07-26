
#define SDL_MAIN_USE_CALLBACKS 1
#include "app.h"
#include <SDL3/SDL_main.h>

App* App::pInstance{nullptr};
static App* pApp = App::GetInstance();
std::mutex App::mtx;

SDL_AppResult SDL_AppInit(void** appstate, int argc, char* argv[])
{
    pApp->Init();
    if(!SDL_CreateWindowAndRenderer("Chip8Emulator",400,400,SDL_WINDOW_BORDERLESS, &pApp->window, &pApp->renderer))
    {
        SDL_Log("Couldn't create window and renderer: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }
    return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppEvent(void *appstate, SDL_Event *event)
{
    if (event->type == SDL_EVENT_KEY_DOWN ||
        event->type == SDL_EVENT_QUIT) {
        return SDL_APP_SUCCESS; 
    }
    return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppIterate(void *appstate)
{
    
   pApp->Execute();
   pApp->Render();

    return SDL_APP_CONTINUE;
}

void SDL_AppQuit(void *appstate, SDL_AppResult result)
{
}