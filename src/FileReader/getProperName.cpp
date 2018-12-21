#include "fileReader.ih"

string FileReader::getProperName(string *str)
{
    replace(str->begin(), str->end(), '.',  ' ');

    char *properName = str->data();
    properName[0] = toupper(properName[0]);
    for (size_t idx = 1; idx < str->length(); ++idx)
    {
        if (properName[idx - 1] == ' ')
            properName[idx] = toupper(properName[idx]);
        else
            properName[idx] = tolower(properName[idx]);
    }
    string properString = properName;

    // Remove any characters that shouldn't be there and remove all trailing whitespace.
    eraseSubStr(properString, "-");
    eraseSubStr(properString, ")");
    eraseSubStr(properString, "(");
    properString.erase(properString.find_last_not_of(" \t\n\r\f\v") + 1);

    return properString;
}