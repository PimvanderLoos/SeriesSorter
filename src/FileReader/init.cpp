#include "fileReader.ih"

void FileReader::init()
{
    // Yeah, I hard coded it. If I can be bothered, I might change that if I can be bothered some day. Who knows.
    d_path = getCurrentPath() + "/";

    d_videoFormats   = {".mkv", ".mp4", ".avi", ".mov", ".flv", ".mpg", ".mpeg"};
    d_ignoredFormats = {".exe", ".jpg",  ".jpeg", ".png", ""};
    d_configPath     = d_path + "config.txt";
    d_configOptions  = {{"logFile", "log.txt"}, {"seriesFolder", "Series/"}, {"moviesFolder", "Movies/"},
                        {"trashFolder", "Trash/"}, {"unsortedFolder", "Unsorted/"}};

    readConfig();
}