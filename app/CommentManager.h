#ifndef COMMENT_MANAGER_H
#define COMMENT_MANAGER_H

#include <string>
#include <sqlite3.h>

class CommentManager {
private:
    sqlite3* db;

public:
    CommentManager(const std::string& dbPath);
    ~CommentManager();

    bool submitComment(const std::string& comment);
    bool uploadFile(const std::string& filePath);
};

#endif