#include "fileReader.ih"

filesystem::path FileReader::getParentDir(filesystem::path const &path)
{
    filesystem::path ret;
    if (filesystem::is_directory(path))
        ret = path;
    else
        ret = path.parent_path();
    return ret;
}