#include "fileReader.ih"

void FileReader::processFile(filesystem::path const &path)
{
    if (!ignoreExtension(path.extension()))
        parseFile(path);
}