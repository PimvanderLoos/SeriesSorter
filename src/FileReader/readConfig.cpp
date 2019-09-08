#include "fileReader.ih"

void FileReader::readConfig()
{
    if (!filesystem::exists(d_configPath))
        writeConfig();
    else
    {
        ifstream config(d_configPath);
        string line;
        while (getline(config, line))
            for (auto &configOption : d_configOptions)
                if (line.find(configOption.first + "=") != string::npos)
                {
                    eraseSubStr(line, configOption.first + "=");
                    configOption.second = line;
                }
    }

    d_sleepTime    = std::stoul(pathFromConfigOption(d_configOptions.find("timeout"       )->second));
    d_logFile      = pathFromConfigOption(d_configOptions.find("logFile"       )->second);
    d_seriesPath   = pathFromConfigOption(d_configOptions.find("seriesFolder"  )->second);
    d_moviesPath   = pathFromConfigOption(d_configOptions.find("moviesFolder"  )->second);
    d_trashPath    = pathFromConfigOption(d_configOptions.find("trashFolder"   )->second);
    d_unsortedPath = pathFromConfigOption(d_configOptions.find("unsortedFolder")->second);

//    logToFile("Paths   :");
//    logToFile("Log     : " + d_logFile.string());
//    logToFile("Series  : " + d_seriesPath);
//    logToFile("Movies  : " + d_moviesPath);
//    logToFile("Trash   : " + d_trashPath);
//    logToFile("Unsorted: " + d_unsortedPath);
}