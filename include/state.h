#pragma once
#include <string>

class state 
{
public:

    state(const std::string& name){mName = name;}

    virtual void Enter(){}
    virtual std::string Execute() const { return "";}
    virtual void Leave(){}

    virtual std::string_view GetName() const {return mName;}

private:
    std::string mName;
    
};