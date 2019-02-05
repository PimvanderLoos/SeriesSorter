#include "fileReader.ih"

void FileReader::parseFile(filesystem::path const &path)
{
    filesystem::path finalPath;
    string file = path.filename().string();
    string extension = path.filename().extension().string();
    std::transform(extension.begin(), extension.end(), extension.begin(), ::tolower);
    if (hasIgnoredExtension(path))
    {
        moveOldFileToTrash(path);
        return;
    }
    string parentDir = path.parent_path().filename().string();

    size_t season = 0;
    size_t episode = 0;
    size_t year = 0;
    string nameAndEpisode;
    string name;

    /* Most series follow the following format:
     * The.100.S05E01.1080p.WEB.x264-METCON[rarbg]/the.100.s05e01.1080p.web.x264-metcon.mkv
     * But then there are some idiotically versioned formats such as this:
     * Scorpion.S04E22.1080p.HDTV.X264-DIMENSION[rarbg]/scorpion.422.1080-dimension.mkv
     * So, to make sure the latter gets sorted properly as well, also look for the season/episode in the parent path.
     */
    // TV SERIES
    if (getNameAndSeasonAndEpisodeFromStr(file, &nameAndEpisode) || getNameAndSeasonAndEpisodeFromStr(parentDir, &nameAndEpisode))
    {
        if (!getSeasonAndEpisodeFromStr(nameAndEpisode, &season, &episode))
        {
            logToFile("SOMEHOW FAILED TO FIND SEASON AND EPISODE FROM FILE:" + nameAndEpisode + " in path: " +
                      path.string() + "... ABORTING...\n");
            return;
        }

        name = nameAndEpisode;
        seriesNameFromStr(&name, season, episode);

        finalPath = d_seriesPath + name + "/" + "Season " + toDoubleFormat(season) + "/"
                    + name + " - S" + toDoubleFormat(season) + "E" + toDoubleFormat(episode) + extension;
    }
    // MOVIE
    else if (getNameAndYearFromStr(file, &name, &year) || getNameAndYearFromStr(parentDir, &name, &year))
        finalPath = d_moviesPath + name + " (" + to_string(year) + ")/" + name + " (" + to_string(year) + ")" + extension;
    else
    {
        logToFile("Failed to parse file: " + path.string());
        return;
    }

    size_t dup = moveFile(path, finalPath);

    if (hasVideoExtension(finalPath))
        writeInfoFile(path, finalPath, dup);
}