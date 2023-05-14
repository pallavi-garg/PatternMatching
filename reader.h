#ifndef FILEREADER_H
#define FILEREADER_H

#include <string>
#include <vector>

class filereader
{
public:
    void read_file(std::string& filePath, std::string& text);
    void read_file_multiline(std::string& filePath, std::vector<std::string>& patterns);
};

#endif