#include "fileReader.ih"

void FileReader::logToFile(std::string const &&str)
{
    // To print something to terminal, first run this command: dup2(saved_stdout, 1);
    freopen(d_logFile.c_str(), "a", stdout);
    cout << str << endl;
}