#include "fileReader.ih"

string FileReader::getTime() const
{
    time_t rawtime;
    struct tm * timeinfo;
    char buffer[80];
    time (&rawtime);
    timeinfo = localtime(&rawtime);
    strftime(buffer,sizeof(buffer),"%Y-%m-%d %H:%M:%S", timeinfo);
    string currentTime(buffer);
    return currentTime;
}