#include "FileManager.h"
#include "DatabaseManager.h"
#include <iostream>
#include <vector>

FileManager::FileManager(DatabaseManager& dbManager) : dbManager(dbManager) {}

void FileManager::saveFile(const std::string& filePath) {
    std::cout << "Saving file: " << filePath << std::endl;
    dbManager.addFileTag(filePath, "default"); // Example of adding a default tag
}

void FileManager::deleteFile(const std::string& filePath) {
    std::cout << "Deleting file: " << filePath << std::endl;
    dbManager.addFileTag(filePath, "deleted"); // Mark file as deleted
}

void FileManager::addTag(const std::string& filePath, const std::string& tag) {
    if (dbManager.addFileTag(filePath, tag)) {
        std::cout << "Tag added successfully: " << tag << std::endl;
    } else {
        std::cout << "Failed to add tag: " << tag << std::endl;
    }
}

std::vector<std::string> FileManager::getTags(const std::string& filePath) {
    return dbManager.getFileTags(filePath);
}
