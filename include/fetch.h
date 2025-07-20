#pragma once
#include "state.h"


class fetch : public state
{
public:
    
    explicit fetch(const std::string& stateName) : state(stateName){}
    ~fetch(){}

    void Enter() override;
    std::string Execute() override;
    void Leave() override;

private:
    std::string mStateName;
};
