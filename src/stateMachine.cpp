#include "stateMachine.h"
#include <utility>
#include <algorithm>

void fetch::Enter()
{
    std::cout << "enter is working" << std::endl;
}
std::string fetch::Execute() const
{
    std::cout << "Execute is working" << std::endl;
    return stateMachine::mStateExecute.data();
}
void fetch::Leave()
{
    std::cout << "Leave is working" << std::endl;
}
//----------------------------------------------------------
void execute::Enter()
{
    std::cout << "enter is working" << std::endl;
}
std::string execute::Execute() const
{
    std::cout << "Execute is working" << std::endl;
    return stateMachine::mStateDecode.data();
}
void execute::Leave()
{
    std::cout << "Leave is working" << std::endl;
}
//----------------------------------------------------------
void decode::Enter()
{
    std::cout << "enter is working" << std::endl;
}
std::string decode::Execute() const
{
    std::cout << "Execute is working" << std::endl;
    return stateMachine::mStatefetch.data();
}
void decode::Leave()
{
    std::cout << "Leave is working" << std::endl;
}


stateMachine::stateMachine() :
    mFetch(stateMachine::mStatefetch.data()), mExecute(stateMachine::mStateExecute.data()),
    mDecode(stateMachine::mStateDecode.data())
{

    AddState(std::make_shared<fetch>(mFetch));
    AddState(std::make_shared<execute>(mExecute));
    AddState(std::make_shared<decode>(mDecode));

    if(!stateQueue.empty())
    {
        currentState = stateQueue.at(stateMachine::mStatefetch);
    }
}
    

void stateMachine::OnEnter()
{   
    if(currentState)
    {
        currentState->Enter();
    }
}

void stateMachine::OnExecute()
{
    if(currentState)
    {
        const std::string_view nextStateName{currentState->Execute()};
        if(!nextStateName.empty())
        {
            const auto findState = [&](std::pair<std::string_view, std::shared_ptr<state>> state){return state.first == nextStateName;};
            std::shared_ptr<state> tempState = std::find_if(stateQueue.begin(), stateQueue.end(), findState)->second;
            nextState = tempState;
        }
    }
}

void stateMachine::OnLeave()
{
    if((currentState != nextState) && nextState.get())
    {
        currentState->Leave();
        currentState = nextState;
    }
}

void stateMachine::AddState(std::shared_ptr<state> State)
{
    const auto stateToAdd{std::make_pair(State->GetName(), State)};
    stateQueue.insert(stateToAdd); 
}
