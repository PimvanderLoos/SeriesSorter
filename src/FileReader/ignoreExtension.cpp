#include "fileReader.ih"

bool FileReader::ignoreExtension(string &&extension)
{
    return extension == ".txt" || extension == ".nfo" || extension == ".jpg" || extension == ".png";
}