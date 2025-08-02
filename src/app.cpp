#include "app.h"


App::App(uint16_t width, uint16_t height) :
mScreenSize(width, height), pStateMachine(std::make_unique<stateMachine>())
{

}

void App::Init(SDL_AppResult& appResult, int argc, char* argv[])
{
    int err{0};
    if(argc != 1)
    {
        std::string filepath;
        filepath = argv[1];
        err = mMemoryManger.LoadRom(filepath);
        appResult = SDL_APP_CONTINUE;
        
    }
    else
    {
        std::cout << "ROM not specified. filepath is required." << std::endl;
        appResult = SDL_APP_FAILURE;
    }

    if(err == -1)
    {
        appResult = SDL_APP_FAILURE;
        std::cout << "ROM Name is incorrect." << std::endl;
    }


}

void App::Execute()
{
    pStateMachine->OnEnter();
    pStateMachine->OnExecute();
    pStateMachine->OnLeave();
}

void App::Render()
{

}