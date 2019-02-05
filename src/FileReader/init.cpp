#include "fileReader.ih"

void FileReader::init()
{
    // Yeah, I hard coded it. If I can be bothered, I might change that if I can be bothered some day. Who knows.
    d_path = getCurrentPath() + "/";

    d_logFile = d_path + "log.txt";
    d_seriesPath = d_path + "Series/";
    d_moviesPath = d_path + "Movies/";

    char* pPath;
    pPath = getenv("XDG_DATA_HOME");

    if (pPath == NULL || *pPath == '\0')
    {
        d_trashPath = getenv("HOME");
        d_trashPath += "/.local/share";
    }
    else
        d_trashPath = pPath;
    d_trashPath += "/Trash/files/";

    d_path += "Unsorted/";

    saved_stdout = dup(1);

    d_videoFormats   = {".mkv", ".mp4", ".avi", ".mov", ".flv", ".mpg", ".mpeg"};
    d_ignoredFormats = {".exe", ".jpg",  ".jpeg", ".png", ""};
}