#include "fileReader.ih"

void FileReader::moveOldDirToTrash(std::filesystem::path const &old)
{
    if (old.string() == d_path)
        return;

    string newPath = old.string();
    eraseSubStr(newPath, d_path);
    newPath = d_trashPath + newPath;

    logToFile("Moving directory: " + old.string() + " to: " + newPath + "\n");

    moveFile(old, newPath);
}