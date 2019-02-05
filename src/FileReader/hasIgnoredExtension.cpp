#include "fileReader.ih"

bool FileReader::hasIgnoredExtension(filesystem::path const &path)
{
    string extension = path.extension();
    std::transform(extension.begin(), extension.end(), extension.begin(), ::tolower);
    return d_ignoredFormats.find(extension) != d_ignoredFormats.end();
}