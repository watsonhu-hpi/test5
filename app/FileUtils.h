#ifndef FILE_UTILS_H
#define FILE_UTILS_H

#include <string>

#include <map>
#include <vector>
#include <string>

class FileUtils {
private:
    std::map<std::string, std::vector<std::string>> fileTags;
public:
    void saveFile(const std::string& filePath);
    void deleteFile(const std::string& filePath);
    void addTag(const std::string& filePath, const std::string& tag);
    void searchFilesByTag(const std::string& tag);
};

#endif