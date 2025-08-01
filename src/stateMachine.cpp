#include "stateMachine.h"
#include <utility>
#include <algorithm>

void fetch::Enter()
{
}
std::string fetch::Execute() const
{
    return stateMachine::mStateExecute.data();
}
void fetch::Leave()
{
}
//----------------------------------------------------------
void execute::Enter()
{
}
std::string execute::Execute() const
{
    return stateMachine::mStateDecode.data();
}
void execute::Leave()
{
}
//----------------------------------------------------------
void decode::Enter()
{
}
std::string decode::Execute() const
{
    return stateMachine::mStatefetch.data();
}
void decode::Leave()
{
}


stateMachine::stateMachine() :
    mFetch(stateMachine::mStatefetch.data()), mExecute(stateMachine::mStateExecute.data()),
    mDecode(stateMachine::mStateDecode.data())
{


    AddState(&mFetch);
    AddState(&mExecute);
    AddState(&mDecode);

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
            const auto findState = [&](std::pair<std::string_view, state*> state){return state.first == nextStateName;};
            state* tempState = std::find_if(stateQueue.begin(), stateQueue.end(), findState)->second;
            nextState = tempState;
        }
    }
}

void stateMachine::OnLeave()
{
    if((currentState != nextState) && nextState)
    {
        currentState->Leave();
        currentState = nextState;
    }
}

void stateMachine::AddState(state* State)
{
    auto stateToAdd{std::make_pair(State->GetName(), State)};
    stateQueue.insert(stateToAdd); 
}
