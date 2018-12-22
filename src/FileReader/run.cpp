#include "fileReader.ih"

void FileReader::run()
{
    if (filesystem::is_empty(d_path))
        return;

    logToFile("\n\n" +
              string("#####################################################\n") +
                      "######## Starting run at " + getTime() + " ########\n"   +
              string("#####################################################\n"));

    for (auto &p : filesystem::directory_iterator(d_path))
    {
        if (p.is_directory())
            processFolder(p.path());
        else
            processFile(p.path());

        moveOldDirToTrash(p);
    }

    logToFile("\n" +
              string("#####################################################\n") +
                      "######## Finished run at " + getTime() + " ########\n"   +
              string("#####################################################\n") + "\n");
}