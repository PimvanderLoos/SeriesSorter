#include "fileReader.ih"

void FileReader::moveOldDirToTrash(std::filesystem::path const &old)
{
    if (old.string() == d_path)
        return;

    if (!safeToDelete(old))
        for (auto &p : filesystem::directory_iterator(old))
        {
            if (p.is_directory())
                moveOldDirToTrash(p.path());
            else
                moveOldFileToTrash(p.path());
        }

    string newPath = old.string();
    eraseSubStr(newPath, d_path);
    newPath = d_trashPath + newPath;
    moveFile(old, newPath);
}