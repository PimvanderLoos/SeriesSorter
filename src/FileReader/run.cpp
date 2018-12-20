#include "fileReader.ih"

void FileReader::run()
{
    time_t rawtime;
    struct tm * timeinfo;
    char buffer[80];
    time (&rawtime);
    timeinfo = localtime(&rawtime);
    strftime(buffer,sizeof(buffer),"%d-%m-%Y %H:%M:%S", timeinfo);
    string currentTime(buffer);

    logToFile("\n\n" +
              string("#####################################################\n") +
                      "######## Starting run at " + currentTime + " ########\n" +
              string("#####################################################\n") + "\n");
    for (auto &p : filesystem::directory_iterator(d_path))
    {
        if (p.is_directory())
            processFolder(p.path());
        else
            processFile(p.path());
    }
}