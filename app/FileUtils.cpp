#include "FileUtils.h"
#include <iostream>
#include <map>
#include <vector>

void FileUtils::saveFile(const std::string& filePath) {
    std::cout << "Saving file: " << filePath << std::endl;
}

std::map<std::string, std::vector<std::string>> fileTags;

void FileUtils::addTag(const std::string& filePath, const std::string& tag) {
    fileTags[filePath].push_back(tag);
    std::cout << "Added tag: " << tag << " to file: " << filePath << std::endl;
}

void FileUtils::searchFilesByTag(const std::string& tag) {
    std::cout << "Searching for files with tag: " << tag << std::endl;
    for (const auto& [filePath, tags] : fileTags) {
        if (std::find(tags.begin(), tags.end(), tag) != tags.end()) {
            std::cout << "File: " << filePath << " has tag: " << tag << std::endl;
        }
    }
}

void FileUtils::deleteFile(const std::string& filePath) {
    std::cout << "Deleting file: " << filePath << std::endl;
}