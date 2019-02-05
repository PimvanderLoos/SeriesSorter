#include "fileReader.ih"

void FileReader::writeInfoFile(filesystem::path const &from, filesystem::path const &to, size_t dup)
{
    filesystem::path parentDir = getParentDir(to);
    filesystem::create_directories(parentDir);

    // The info file doesn't have an extension, so it won't interfere with .txt or .nfo files.
    string infoFilePath = to.string();
    eraseSubStr(infoFilePath, to.extension());

    ofstream infoFile;
    infoFile.open(infoFilePath, fstream::app);
    infoFile << dup << ": ";
    infoFile << from.filename() << "\n";
    infoFile.close();
}