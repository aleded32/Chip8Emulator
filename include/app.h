#pragma once
#include <SDL3/SDL.h>
#include <iostream>
#include <mutex>
#include "stateMachine.h"


class App
{
public:
    
    App(uint16_t width, uint16_t height);

    void Execute();
    void Render();

    SDL_Window* window{nullptr};
    SDL_Renderer* renderer{nullptr};

private:

    std::unique_ptr<stateMachine> pStateMachine;

    struct size
    {
        uint16_t width{0};
        uint16_t height{0};

        size(uint16_t _width, uint16_t _height)
            : width(_width), height(_height)
        {}
    };

    size mScreenSize;

public:
    size GetScreenSize() const{return mScreenSize;}
};
