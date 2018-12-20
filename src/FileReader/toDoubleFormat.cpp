#include "fileReader.ih"

string FileReader::toDoubleFormat(size_t count)
{
    string ret;
    if (count < 10)
        ret = "0" + to_string(count);
    else
        ret = to_string(count);
    return ret;
}