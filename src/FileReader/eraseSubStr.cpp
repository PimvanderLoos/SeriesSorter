#include "fileReader.ih"

void FileReader::eraseSubStr(string &mainStr, string const &toErase)
{
    size_t pos;
    while ((pos = mainStr.find(toErase))!= std::string::npos)
        mainStr.erase(pos, toErase.length());
}