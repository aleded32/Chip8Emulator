#pragma once

#include <unordered_map>
#include <memory>
#include "state.h"
#include "fetch.h"
#include "execute.h"
#include "decode.h"

class stateMachine
{
public:

    stateMachine();
    ~stateMachine();

    void OnEnter();
    void OnExecute();
    void OnLeave();

    void AddState(const std::string& name, std::shared_ptr<state> state);

protected: 
    std::shared_ptr<state> fetchState;
    std::shared_ptr<state> executeState;
    std::shared_ptr<state> decodeState;
    
private:
    std::unordered_map<std::string, std::shared_ptr<state>> stateQueue;
    std::shared_ptr<state> currentState;
    std::shared_ptr<state> nextState;
};