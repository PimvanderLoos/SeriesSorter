#include "fileReader.ih"

bool FileReader::ignoreExtension(string &&extension)
{
    return extension == ".txt" || extension == ".jpg" || extension == ".png";
}