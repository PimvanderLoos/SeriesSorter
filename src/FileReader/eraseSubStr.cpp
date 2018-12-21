#include "fileReader.ih"

void FileReader::eraseSubStr(string &mainStr, string const &toErase)
{
    dup2(saved_stdout, 1);
    cout << "Removing: " << toErase << " from: " << mainStr << "\n";
    size_t pos;
    while ((pos = mainStr.find(toErase))!= std::string::npos)
    {
        cout << "FOUND SOMETHING. Lenght = " << toErase.length() << "\n";
        mainStr.erase(pos, toErase.length());
    }
    cout << "Result: " << mainStr << "\n\n";
}