#include "fileReader.ih"

bool FileReader::hasVideoExtension(filesystem::path const &path)
{
    string extension = path.extension();
    std::transform(extension.begin(), extension.end(), extension.begin(), ::tolower);
    return d_videoFormats.find(extension) != d_videoFormats.end();
}