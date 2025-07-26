#pragma once
#include <string>

class state 
{
public:

    state() = default;

    virtual void Enter(){}
    virtual std::string Execute() const { return "";}
    virtual void Leave(){}

private:
    
};