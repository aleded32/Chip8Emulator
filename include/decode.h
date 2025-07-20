#pragma once
#include "state.h"


class decode : public state
{
public:
    
    explicit decode(const std::string& stateName) : state(stateName){}
    ~decode(){}

    void Enter() override;
    std::string Execute() override;
    void Leave() override;

private:
    std::string mStateName;
};
