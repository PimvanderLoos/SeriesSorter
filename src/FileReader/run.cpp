#include "fileReader.ih"

void FileReader::run()
{
    if (filesystem::is_empty(d_unsortedPath))
        return;

    logToFile("\n\n" +
              string("#####################################################\n") +
                      "######## Starting run at " + getTime() + " ########\n"   +
              string("#####################################################\n"));

    for (auto &p : filesystem::directory_iterator(d_unsortedPath))
    {
        if (p.is_directory())
        {
            processFolder(p.path());
            moveOldDirToTrash(p.path());
        }
        else
        {
            parseFile(p.path());
            if (filesystem::exists(p.path()))
                moveOldDirToTrash(p.path());
        }
    }

    logToFile("\n" +
              string("#####################################################\n") +
                      "######## Finished run at " + getTime() + " ########\n"   +
              string("#####################################################\n") + "\n");
}