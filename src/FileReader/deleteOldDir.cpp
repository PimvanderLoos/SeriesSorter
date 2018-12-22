#include "fileReader.ih"

void FileReader::deleteOldDir(std::filesystem::path const &old)
{
    if (!safeToDelete(old))
        return;

    filesystem::remove_all(old);

    logToFile("Deleting directory: " + old.string() + "\n");
}