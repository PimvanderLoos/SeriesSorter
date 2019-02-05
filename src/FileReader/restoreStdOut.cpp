#include "fileReader.ih"

void FileReader::restoreStdOut()
{
    dup2(saved_stdout, 1);
}