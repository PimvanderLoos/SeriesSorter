#include "fileReader.ih"

void FileReader::moveOldFileToTrash(std::filesystem::path const &old)
{
    if (old.string() == d_unsortedPath)
        return;

    string newPath = old.string();

    eraseSubStr(newPath, d_unsortedPath);
    newPath = d_trashPath + newPath;

    logToFile("Trashing File: " + old.string());
    moveFile(old, newPath);
}