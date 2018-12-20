#ifndef SERIESSORTER_FILEREADER_H
#define SERIESSORTER_FILEREADER_H

#include "iosfwd"
#include "string"
#include <filesystem>

class FileReader
{
    private:
        // Store root path and location of series and movies folders as well as the location of the logfile.
        std::string d_path;
        std::string d_seriesPath;
        std::string d_moviesPath;
        std::filesystem::path d_logFile;

        // Setup this object.
        void init();

        // Get path the app was launched in.
        std::string getCurrentPath() const;

        // Process a specific file.
        void processFile(std::filesystem::path const &path);

        // Process all files in a specific folder.
        void processFolder(std::filesystem::path const &path);

        // Check if the extension should be processed or not (I don't care about .txt files).
        bool ignoreExtension(std::string &&extension);

        // Generate a new path from a file and move the file to the appropriate location afterwards.
        void parseFile(std::filesystem::path const &path);

        // The format is sxxexx, so convert 4 to 04 (i.e. s04e12).
        std::string toDoubleFormat(size_t count);

        // Get current time.
        std::string getTime() const;

        // Move a file.
        void moveFile(std::filesystem::path const &from, std::filesystem::path const &to);

        // Check if it's safe to delete a directory.
        bool safeToDelete(std::filesystem::path const &old);

        // Delete specified directory.
        void deleteOldDir(std::filesystem::path const &old);

        // Log a string to file.
        void logToFile(std::string const &&str);

        // Get Name + Season + Episode from a string.
        // ("Mr.Robot.s01e04.uploadedbysomeone.more.spam.here.rarbg.mkv") -> ("Mr.Robot.s01e04")
        bool getNameAndSeasonAndEpisodeFromStr(std::string const &str, std::string *result);

        // Extract the name of a series from a specified string. To be used after getNameAndSeasonAndEpisodeFromStr.
        void seriesNameFromStr(std::string *str);

        // Extract season and episode from a provided string. To be used after getNameAndSeasonAndEpisodeFromStr.
        bool getSeasonAndEpisodeFromStr(std::string const &str, size_t *season, size_t *episode);

        // Capitalize first letters of every sentence. ("house of cards" -> "House Of Cards").
        std::string getProperName(std::string &str);

    public:
        FileReader();
        void run();
};


#endif
