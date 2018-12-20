#include "fileReader.ih"

void FileReader::logToFile(std::string const &&str)
{
    freopen(d_logFile.c_str(), "a", stdout);
    cout << str << endl;
}