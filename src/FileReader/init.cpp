#include "fileReader.ih"

void FileReader::init()
{
    d_path = getCurrentPath() + "/";

    d_logFile = d_path + "log.txt";
    d_seriesPath = d_path + "Series/";
    d_moviesPath = d_path + "Movies/";

    d_path += "Unsorted/";

    cout << "Log file is at: " << d_logFile << "\n";
}