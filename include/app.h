#pragma once
#include <SDL3/SDL.h>
#include <iostream>
#include <mutex>
#include "stateMachine.h"


class App
{
public:
    
    App(App const&) = delete;

    static App* GetInstance()
    {
        if(!pInstance)
        {
            std::lock_guard<std::mutex> lock(mtx);
            App newInstance;
            pInstance = &newInstance;
        }
        return pInstance;
    }

    void Init();
    void Execute();
    void Render();

    SDL_Window* window{nullptr};
    SDL_Renderer* renderer{nullptr};

private:

    
    App() = default;


    static App* pInstance;
    static std::mutex mtx;
    std::shared_ptr<stateMachine> pStateMachine;
};
