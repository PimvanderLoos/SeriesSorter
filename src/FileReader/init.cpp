#include "fileReader.ih"

void FileReader::init()
{
    // Yeah, I hard coded it. If I can be bothered, I might change that if I can be bothered some day. Who knows.
    d_path = getCurrentPath() + "/";

    d_logFile = d_path + "log.txt";
    d_seriesPath = d_path + "Series/";
    d_moviesPath = d_path + "Movies/";

    d_path += "Unsorted/";
}