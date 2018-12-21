#include "fileReader.ih"

bool FileReader::getNameAndSeasonAndEpisodeFromStr(string const &str, string *result)
{
    // Match "Lucifer S03E04" and "Lucifer s03 e04" and any combination of the two.
    regex nameAndEpisodeRegex("[[a-z|A-z|0-9]*.*]*.[S|s][0-9]{2}[ ]{0,1}[E|e][0-9]{2}");
    smatch nameAndEpisodeMatch;
    if (regex_search(str, nameAndEpisodeMatch, nameAndEpisodeRegex))
    {
        *result = nameAndEpisodeMatch[0];
        return true;
    }
    return false;
}