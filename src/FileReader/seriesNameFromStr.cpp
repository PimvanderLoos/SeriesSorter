#include "fileReader.ih"

void FileReader::seriesNameFromStr(string *str)
{
    str->erase(str->length() - 7, 7);
    replace(str->begin(), str->end(), '.',  ' ');
    *str = getProperName(*str);
}