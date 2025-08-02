#include "memoryManager.h"
#include <fstream>
#include <iostream>
#include <filesystem>

memoryManager::memoryManager()
{
    LoadFontSet();
}

void memoryManager::LoadFontSet()
{
    for(size_t index{mkFontStartAddress}; index < 0x9F; ++index)
    {
        mMemory[index] = mFontset[index - mkFontStartAddress];
    }
}

int memoryManager::LoadRom(std::string& filename)
{
    std::string filepath{std::filesystem::current_path().c_str()};

    filepath.append("/ROMS/" + filename);
    std::ifstream stream(filepath, std::ios::binary);

    if(!stream.is_open())
    {
        std::cout << "could not locate " << filepath << std::endl;
        return -1;
    }

    std::streampos bufferSize{stream.tellg()};
    uint8_t *buffer = new uint8_t(bufferSize);

    stream.seekg(bufferSize);
    stream.read(reinterpret_cast<char*>(&buffer), bufferSize);

    for(size_t index{mkStartAddress}; index < mMemory.size(); ++index)
    {
        mMemory.at(index) = buffer[index - mkStartAddress];
    }

    delete buffer;

    return 0;

}