#include "fileReader.ih"

void FileReader::deleteOldDir(std::filesystem::path const &old)
{
    filesystem::path directory = old.parent_path();
    if (!safeToDelete(old))
        return;
    if (directory.string() + "/" == d_path)
        return;
    filesystem::remove_all(directory);
    logToFile("Deleting directory: " + directory.string() + "\n");
}