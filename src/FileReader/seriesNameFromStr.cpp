#include "fileReader.ih"

void FileReader::seriesNameFromStr(string *str, size_t season, size_t episode)
{
    eraseSubStr(*str, "s" + toDoubleFormat(season) + "e" + toDoubleFormat(episode));
    eraseSubStr(*str, "S" + toDoubleFormat(season) + "E" + toDoubleFormat(episode));
    eraseSubStr(*str, "s" + toDoubleFormat(season) + " e" + toDoubleFormat(episode));
    eraseSubStr(*str, "S" + toDoubleFormat(season) + " E" + toDoubleFormat(episode));
    *str = getProperName(str);
}