#include "fileReader.ih"

size_t FileReader::moveFile(filesystem::path const &from, filesystem::path const &to, size_t dup)
{
    filesystem::path finalDestination = to;
    if (dup != 0)
    {
        if (filesystem::is_directory(finalDestination))
            finalDestination.replace_filename(to.filename().string() + "_" + to_string(dup));
        else
            finalDestination.replace_filename(to.stem().string() + "_" + to_string(dup) + to.extension().string());
    }

    if (filesystem::exists(finalDestination))
        return moveFile(from, to, dup + 1);

    filesystem::path parentDir = getParentDir(to);
    filesystem::create_directories(parentDir);

    filesystem::rename(from, finalDestination);
    logToFile("Moving file from: " + from.string() + " to: " + finalDestination.string() + "\n");

    return dup;
}