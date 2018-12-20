#include "fileReader.ih"

void FileReader::moveFile(filesystem::path const &from, filesystem::path const &to)
{
    filesystem::path directory = to.parent_path();
    if (!filesystem::exists(directory))
        logToFile("Creating Directory " + directory.string() + " status: " +
                  to_string(filesystem::create_directories(directory)));
    filesystem::rename(from, to);
    logToFile("Moving file from: " + from.string() + " to: " + to.string() + "\n");
}