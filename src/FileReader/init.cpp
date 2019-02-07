#include "fileReader.ih"

void FileReader::init()
{
    // Yeah, I hard coded it. If I can be bothered, I might change that if I can be bothered some day. Who knows.
    d_path = getCurrentPath() + "/";

    readConfig();

    saved_stdout = dup(1);

    d_videoFormats   = {".mkv", ".mp4", ".avi", ".mov", ".flv", ".mpg", ".mpeg"};
    d_ignoredFormats = {".exe", ".jpg",  ".jpeg", ".png", ""};
}