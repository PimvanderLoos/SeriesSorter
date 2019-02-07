#include "fileReader.ih"

string FileReader::pathFromConfigOption(string const &option)
{
    if (option.at(0) == '/')
        return option;
    return d_path + option;
}