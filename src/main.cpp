
#define SDL_MAIN_USE_CALLBACKS 1
#include "app.h"
#include <SDL3/SDL_main.h>

App app(1920,1080);

SDL_AppResult SDL_AppInit(void** appstate, int argc, char* argv[])
{
    if(!SDL_CreateWindowAndRenderer("Chip8Emulator",400,400,SDL_WINDOW_BORDERLESS, &app.window, &app.renderer))
    {
        SDL_Log("Couldn't create window and renderer: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    SDL_AppResult Res;
    app.Init(Res, argc, argv);

    return Res;
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
   
   app.Execute();
   app.Render();

    return SDL_APP_CONTINUE;
}

void SDL_AppQuit(void *appstate, SDL_AppResult result)
{
}