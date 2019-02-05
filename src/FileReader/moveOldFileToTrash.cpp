#include "fileReader.ih"

void FileReader::moveOldFileToTrash(std::filesystem::path const &old)
{
    if (old.string() == d_path)
        return;

    string newPath = old.string();

    eraseSubStr(newPath, d_path);
    newPath = d_trashPath + newPath;

    logToFile("Trashing File: " + old.string());
    moveFile(old, newPath);
}