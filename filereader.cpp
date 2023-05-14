#include <fstream>
#include <string>
#include "reader.h"

void filereader::read_file(std::string& filePath, std::string& text)
{
    std::ifstream dataFile;
    dataFile.open(filePath);
    
    if (dataFile.is_open())
    {
        text.assign((std::istreambuf_iterator<char>(dataFile) ), (std::istreambuf_iterator<char>()));
    }
    dataFile.close();
}

void filereader::read_file_multiline(std::string& filePath, std::vector<std::string>& patterns)
{
    std::string line = "";
    std::ifstream dataFile;
    dataFile.open(filePath);
    
    if (dataFile.is_open())
    {
        std::getline(dataFile, line);
        while (dataFile.good())
        {
            std::getline(dataFile, line);
            if (line.length() == 7)
                patterns.push_back(line);
            
            
        }
    }
    dataFile.close();
}