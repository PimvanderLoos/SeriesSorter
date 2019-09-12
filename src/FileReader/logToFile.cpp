#include "fileReader.ih"

void FileReader::logToFile(std::string const &&str)
{
    ofstream logFile;
    logFile.open(d_logFile);
    logFile << str << endl;
    logFile.close();
}