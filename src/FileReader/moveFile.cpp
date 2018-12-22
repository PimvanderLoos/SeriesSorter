#include "fileReader.ih"

void FileReader::moveFile(filesystem::path const &from, filesystem::path const &to)
{
    filesystem::path parentDir = getParentDir(to);

    filesystem::create_directories(parentDir);

    filesystem::rename(from, to);
    logToFile("Moving file from: " + from.string() + " to: " + to.string() + "\n");
}