#include "decode.h"
#include <iostream>

void decode::Enter()
{
    std::cout << "enter is working" << std::endl;
}
std::string decode::Execute()
{
    std::cout << "Execute is working" << std::endl;
    return "fetch";
}

void decode::Leave()
{
    std::cout << "Leave is working" << std::endl;
}