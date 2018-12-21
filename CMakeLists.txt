cmake_minimum_required(VERSION 3.10)
project(SeriesSorter)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_PREFIX_PATH "/usr/bin/x86_64-linux-gnu-g++-8")
include_directories("src/")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -pedantic -O3 -Wall -fopenmp -Wno-comment -g")


set(INTERNAL_HEADER_FILES
        src/main.ih
        src/FileReader/fileReader.ih
        )

set(HEADER_FILES
        src/FileReader/fileReader.h
        )

set(SOURCE_FILES
        src/main.cpp
        src/FileReader/fileReader.cpp
        src/FileReader/run.cpp src/FileReader/processFile.cpp src/FileReader/processFolder.cpp
        src/FileReader/toDoubleFormat.cpp src/FileReader/seriesNameFromStr.cpp src/FileReader/getProperName.cpp
        src/FileReader/getNameAndSeasonAndEpisodeFromStr.cpp src/FileReader/getSeasonAndEpisodeFromStr.cpp
        src/FileReader/parseFile.cpp src/FileReader/moveFile.cpp src/FileReader/deleteOldDir.cpp
        src/FileReader/safeToDelete.cpp src/FileReader/logToFile.cpp src/FileReader/init.cpp
        src/FileReader/getCurrentPath.cpp src/FileReader/ignoreExtension.cpp src/FileReader/getTime.cpp
        src/FileReader/getNameAndYearFromStr.cpp src/FileReader/eraseSubStr.cpp)

add_executable(SeriesSorter ${HEADER_FILES} ${INTERNAL_HEADER_FILES} ${SOURCE_FILES})

target_link_libraries(SeriesSorter stdc++fs)