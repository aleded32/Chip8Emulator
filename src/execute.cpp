#include "execute.h"
#include <iostream>

void execute::Enter()
{
    std::cout << "enter is working" << std::endl;
}
std::string execute::Execute()
{
    std::cout << "Execute is working" << std::endl;
    return "decode";
}

void execute::Leave()
{
    std::cout << "Leave is working" << std::endl;
}