#include "fetch.h"
#include <iostream>

void fetch::Enter()
{
    std::cout << "enter is working" << std::endl;
}
std::string fetch::Execute()
{
    std::cout << "Execute is working" << std::endl;
    return "execute";
}

void fetch::Leave()
{
    std::cout << "Leave is working" << std::endl;
}