#include "app.h"
void App::Init()
{
    pStateMachine = std::make_shared<stateMachine>();
}

void App::Execute()
{
    pStateMachine.get()->OnEnter();
    pStateMachine.get()->OnExecute();
    pStateMachine.get()->OnLeave();
}

void App::Render()
{
    
}