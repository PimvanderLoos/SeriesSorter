#include "fileReader.ih"

bool FileReader::getSeasonAndEpisodeFromStr(string const &str, size_t *season, size_t *episode)
{
    // Match "S03E04" and "s03 e04" and any combination of the two.
    regex episodeAndSeasonRegex1("[S|s][0-9]{2}[E|e][0-9]{2}");
    smatch episodeAndSeasonMatch1;
    regex episodeAndSeasonRegex2("[S|s][0-9]{2}[ ][E|e][0-9]{2}");
    smatch episodeAndSeasonMatch2;

    dup2(saved_stdout, 1);

    if (regex_search(str, episodeAndSeasonMatch1, episodeAndSeasonRegex1))
    {
        cout << "NON MORONIC NAMING SCHEME FOUND!\n";
        string episodeAndSeason = episodeAndSeasonMatch1[0];
        *season  = 10 * ((size_t) episodeAndSeason[1] - 48) + (size_t) episodeAndSeason[2] - 48;
        *episode = 10 * ((size_t) episodeAndSeason[4] - 48) + (size_t) episodeAndSeason[5] - 48;
        cout << "EP:" << *episode << " SE:" << *season << "\n";
        return true;
    }
    else if (regex_search(str, episodeAndSeasonMatch2, episodeAndSeasonRegex2))
    {
        cout << "MORONIC NAMING SCHEME FOUND!\n";
        string episodeAndSeason = episodeAndSeasonMatch2[0];
        *season  = 10 * ((size_t) episodeAndSeason[1] - 48) + (size_t) episodeAndSeason[2] - 48;
        *episode = 10 * ((size_t) episodeAndSeason[5] - 48) + (size_t) episodeAndSeason[6] - 48;
        cout << "EP:" << *episode << " SE:" << *season << "\n";
        return true;
    }
    logToFile("SOMEHOW FAILED TO FIND SEASON AND EPISODE FROM STRING:" + str + "\n");
    return false;
}