#include "fileReader.ih"

bool FileReader::getNameAndYearFromStr(string const &str, string *name, size_t *year)
{
    // Match "The.Avengers.2012.", but make sure it's not 1080p.
    regex nameAndYearRegex("[[a-z|A-z|0-9]*.*]*.[ ]{0,1}[0-9]{4}[ |.|))]");
    smatch nameAndYearMatch;
    if (regex_search(str, nameAndYearMatch, nameAndYearRegex))
    {
        string nameAndYear = nameAndYearMatch[0];

        regex yearRegex("[0-9]{4}");
        smatch yearMatch;

        string yearStr;
        // default constructor = end-of-sequence:
        std::regex_token_iterator<std::string::iterator> rend;
        std::regex_token_iterator<std::string::iterator> regex (nameAndYear.begin(), nameAndYear.end(), yearRegex);
        for ( ; regex != rend; ++regex)
            yearStr = regex->str();

        eraseSubStr(nameAndYear, yearStr);
        *name = getProperName(&nameAndYear);
        *year = 0;
        *year += 1000 * ((size_t) yearStr[0] - 48);
        *year +=  100 * ((size_t) yearStr[1] - 48);
        *year +=   10 * ((size_t) yearStr[2] - 48);
        *year +=    1 * ((size_t) yearStr[3] - 48);
        return true;
    }
    return false;
}