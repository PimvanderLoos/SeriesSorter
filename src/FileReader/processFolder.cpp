#include "fileReader.ih"

void FileReader::processFolder(filesystem::path const &path)
{
    for (auto &p : filesystem::directory_iterator(path))
    {
        // Recursively do this shit.
        if (p.is_directory())
            processFolder(p.path());
        else
            parseFile(p);
    }
}