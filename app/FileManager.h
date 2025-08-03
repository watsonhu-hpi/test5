#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include <string>
#include <vector>
#include "DatabaseManager.h"

class FileManager {
private:
    DatabaseManager& dbManager;

public:
    FileManager(DatabaseManager& dbManager);

    void saveFile(const std::string& filePath);
    void deleteFile(const std::string& filePath);
    void addTag(const std::string& filePath, const std::string& tag);
    std::vector<std::string> getTags(const std::string& filePath);
};

#endif