#include "CommentManager.h"
#include <iostream>
#include <fstream>
#include <sqlite3.h>

CommentManager::CommentManager(const std::string& dbPath) {
    sqlite3_open(dbPath.c_str(), &db);
    const char* createTableQuery = "CREATE TABLE IF NOT EXISTS comments (id INTEGER PRIMARY KEY, comment TEXT, file_path TEXT);";
    sqlite3_exec(db, createTableQuery, nullptr, nullptr, nullptr);
}

CommentManager::~CommentManager() {
    sqlite3_close(db);
}

bool CommentManager::submitComment(const std::string& comment) {
    const char* insertQuery = "INSERT INTO comments (comment) VALUES (?);";
    sqlite3_stmt* stmt;
    sqlite3_prepare_v2(db, insertQuery, -1, &stmt, nullptr);
    sqlite3_bind_text(stmt, 1, comment.c_str(), -1, SQLITE_STATIC);

    if (sqlite3_step(stmt) == SQLITE_DONE) {
        sqlite3_finalize(stmt);
        return true;
    }

    sqlite3_finalize(stmt);
    return false;
}

bool CommentManager::uploadFile(const std::string& filePath) {
    std::ifstream file(filePath);
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filePath << std::endl;
        return false;
    }

    const char* insertQuery = "INSERT INTO comments (file_path) VALUES (?);";
    sqlite3_stmt* stmt;
    sqlite3_prepare_v2(db, insertQuery, -1, &stmt, nullptr);
    sqlite3_bind_text(stmt, 1, filePath.c_str(), -1, SQLITE_STATIC);

    if (sqlite3_step(stmt) == SQLITE_DONE) {
        sqlite3_finalize(stmt);
        return true;
    }

    sqlite3_finalize(stmt);
    return false;
}