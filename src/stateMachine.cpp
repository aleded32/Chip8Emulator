#include "stateMachine.h"
#include <utility>
#include <algorithm>

stateMachine::stateMachine() : 
    fetchState(std::make_shared<fetch>("fetch")),  executeState(std::make_shared<execute>("execute")),
    decodeState(std::make_shared<decode>("decode"))
{

    AddState(fetchState.get()->getName(), fetchState);
    AddState(executeState.get()->getName(), executeState);
    AddState(decodeState.get()->getName(), decodeState);

    if(!stateQueue.empty())
    {
        currentState = stateQueue.at("fetch");
    }
}

stateMachine::~stateMachine()
{
}
    

void stateMachine::OnEnter()
{
    if(currentState.get() != nullptr)
    {
        currentState.get()->Enter();
    }
}

void stateMachine::OnExecute()
{
    if(currentState.get() != nullptr)
    {
        std::string nextStateName =  currentState.get()->Execute();

        const auto findState = [&](std::pair<std::string, std::shared_ptr<state>> state){return state.first == nextStateName;};
        std::shared_ptr<state> tempState = std::find_if(stateQueue.begin(), stateQueue.end(), findState)->second;
        nextState = tempState;
    }

}

void stateMachine::OnLeave()
{
    if(currentState.get() != nullptr)
    {
        currentState->Leave();
        currentState = nextState;
    }
}

void stateMachine::AddState(const std::string& name, std::shared_ptr<state> State)
{
    const auto stateToAdd{std::make_pair(name, State)};
    stateQueue.insert(stateToAdd); 
}
