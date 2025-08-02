#include "app.h"


App::App(uint16_t width, uint16_t height) :
mScreenSize(width, height), pStateMachine(std::make_unique<stateMachine>())
{

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