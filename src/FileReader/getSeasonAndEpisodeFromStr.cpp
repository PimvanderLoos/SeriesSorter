#include "fileReader.ih"

bool FileReader::getSeasonAndEpisodeFromStr(string const &str, size_t *season, size_t *episode)
{
    regex episodeAndSeasonRegex("[S|s][0-9]{2}[E|e][0-9]{2}");
    smatch episodeAndSeasonMatch;

    if (regex_search(str, episodeAndSeasonMatch, episodeAndSeasonRegex))
    {
        string episodeAndSeason = episodeAndSeasonMatch[0];
        *season  = 10 * ((size_t) episodeAndSeason[1] - 48) + (size_t) episodeAndSeason[2] - 48;
        *episode = 10 * ((size_t) episodeAndSeason[4] - 48) + (size_t) episodeAndSeason[5] - 48;
        return true;
    }
    logToFile("SOMEHOW FAILED TO FIND SEASON AND EPISODE FROM STRING:" + str + "\n");
    return false;
}