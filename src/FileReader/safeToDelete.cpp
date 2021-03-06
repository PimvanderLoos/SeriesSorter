#include "fileReader.ih"

bool FileReader::safeToDelete(std::filesystem::path const &old)
{
    filesystem::path parentDir = getParentDir(old);

    if (parentDir.string() + "/" == d_unsortedPath)
        return false;

    for (auto &p : filesystem::directory_iterator(parentDir))
    {
        if (p.is_directory() && !p.path().empty())
            return safeToDelete(p.path());
        else if (hasIgnoredExtension(p.path()))
            return false;
    }
    return true;
}