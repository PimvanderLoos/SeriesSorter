#include "fileReader.ih"

void FileReader::writeConfig()
{
    ofstream config(d_configPath);
    if (!config)
    {
        cout << "FAILED TO WRITE CONFIG!";
        return;
    }
    for (auto const &x : d_configOptions)
        config << x.first << "=" << x.second << "\n";
}