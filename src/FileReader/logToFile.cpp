#include "fileReader.ih"

void FileReader::logToFile(std::string const &&str)
{
    // TODO: Use function pointers or something to allow for debugging to console instead of file.
    ofstream logFile;
    logFile.open(d_logFile);
    logFile << str << endl;
    logFile.close();
}