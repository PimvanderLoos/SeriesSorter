#include "fileReader.ih"

bool FileReader::safeToDelete(std::filesystem::path const &old)
{
    filesystem::path directory = old.parent_path();
    if (directory.string() + "/" == d_path)
        return false;

    for (auto &p : filesystem::directory_iterator(directory))
    {
        // If the directory contains another folder (subs?) or if it's a filetype that needs to be processed
        // DON'T DELETE IT.
        if (p.is_directory())
            return false;
        else if (!ignoreExtension(p.path().extension()))
            return false;
    }
    return true;
}