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


stateMachine::stateMachine()
{

    std::shared_ptr<state> fetchState{std::make_shared<fetch>()};
    std::shared_ptr<state> executeState{std::make_shared<execute>()};
    std::shared_ptr<state> decodeState{std::make_shared<decode>()};


    AddState(stateMachine::mStatefetch, fetchState);
    AddState(stateMachine::mStateExecute, executeState);
    AddState(stateMachine::mStateDecode, decodeState);

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
        const std::string nextStateName{currentState->Execute()};
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
    if(currentState)
    {
        currentState->Leave();
        currentState = nextState;
    }
}

void stateMachine::AddState(const std::string_view& name, std::shared_ptr<state> State)
{
    const auto stateToAdd{std::make_pair(name, State)};
    stateQueue.insert(stateToAdd); 
}
