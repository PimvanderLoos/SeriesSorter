#include "fileReader.ih"

void FileReader::moveOldFileToTrash(std::filesystem::path const &old)
{
    if (old.string() == d_path)
        return;

    if (!ignoreExtension(old))
    {
        deleteOldDir(old);
        return;
    }

    string newPath = old.string();

    eraseSubStr(newPath, d_path);
    newPath = d_trashPath + newPath;

    logToFile("Moving File: " + old.string() + " to: " + newPath + "\n");
    moveFile(old, newPath);
}