#pragma once

#include <iostream>
#include <unordered_map>
#include <memory>
#include <string>
#include "state.h"

class fetch : public state
{
public:
    
    fetch(const std::string& name) : state(name){}

    void Enter() override;
    std::string Execute() const override;
    void Leave() override;

private:
};

class execute : public state
{
public:
    
    execute(const std::string& name) : state(name){}

    void Enter() override;
    std::string Execute() const override;
    void Leave() override;

private:
};

class decode : public state
{
public:
    
    decode(const std::string& name) : state(name){}

    void Enter() override;
    std::string Execute() const override;
    void Leave() override;

private:

};


class stateMachine
{
public:
    stateMachine();
    void OnEnter();
    void OnExecute();
    void OnLeave();
    void AddState(state* State);
 

private:
    std::unordered_map<std::string_view, state*> stateQueue;
    state* currentState{nullptr};
    state* nextState{nullptr};

    fetch mFetch;
    execute mExecute;
    decode mDecode;

public:
    static constexpr std::string_view mStatefetch = "fetch";
    static constexpr std::string_view mStateExecute = "execute"; 
    static constexpr std::string_view mStateDecode = "decode";
};