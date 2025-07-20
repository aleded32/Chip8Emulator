#pragma once
#include <string>

class state 
{
public:

    state(const std::string& stateName){ mStateName = stateName;};
    virtual ~state(){}

    virtual void Enter(){}
    virtual std::string Execute(){ return "";}
    virtual void Leave(){}

    virtual std::string getName() const { return mStateName;}

private:
    std::string mStateName;
};