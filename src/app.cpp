#include "app.h"
void App::Init()
{
    pStateMachine = new stateMachine();
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