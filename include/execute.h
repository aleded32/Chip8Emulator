#pragma once
#include "state.h"


class execute : public state
{
public:
    
    explicit execute(const std::string& stateName) : state(stateName){}

    void Enter() override;
    std::string Execute() override;
    void Leave() override;

private:
    std::string mStateName;
};
