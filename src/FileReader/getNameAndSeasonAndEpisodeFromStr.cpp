#include "fileReader.ih"

bool FileReader::getNameAndSeasonAndEpisodeFromStr(string const &str, string *result)
{
    regex nameAndEpisodeRegex("[[a-z|A-z|0-9]*.*]*.[S|s][0-9]{2}[E|e][0-9]{2}");
    smatch nameAndEpisodeMatch;
    if (regex_search(str, nameAndEpisodeMatch, nameAndEpisodeRegex))
    {
        *result = nameAndEpisodeMatch[0];
        return true;
    }
    return false;
}