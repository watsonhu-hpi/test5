#include "DatabaseManager.h"
#include <iostream>
#include <sqlite3.h>
#include <string>
#include <vector>

DatabaseManager::DatabaseManager(const std::string& dbPath) {
    sqlite3_open(dbPath.c_str(), &db);
    const char* createUsersTable = "CREATE TABLE IF NOT EXISTS users (id INTEGER PRIMARY KEY, username TEXT UNIQUE, password TEXT, role TEXT);";
    const char* createCommentsTable = "CREATE TABLE IF NOT EXISTS comments (id INTEGER PRIMARY KEY, comment TEXT, parent_id INTEGER, upvotes INTEGER DEFAULT 0, downvotes INTEGER DEFAULT 0, file_path TEXT, category TEXT, sentiment TEXT);";
    const char* createActivityLogTable = "CREATE TABLE IF NOT EXISTS activity_log (id INTEGER PRIMARY KEY, user_id INTEGER, action TEXT, timestamp DATETIME DEFAULT CURRENT_TIMESTAMP);";
    const char* createNotificationsTable = "CREATE TABLE IF NOT EXISTS notifications (id INTEGER PRIMARY KEY, user_id INTEGER, message TEXT, is_read INTEGER DEFAULT 0, timestamp DATETIME DEFAULT CURRENT_TIMESTAMP);";
    const char* createFileVersionsTable = "CREATE TABLE IF NOT EXISTS file_versions (id INTEGER PRIMARY KEY, file_id INTEGER, version INTEGER, file_path TEXT, timestamp DATETIME DEFAULT CURRENT_TIMESTAMP);";
    sqlite3_exec(db, createUsersTable, nullptr, nullptr, nullptr);
    sqlite3_exec(db, createCommentsTable, nullptr, nullptr, nullptr);
    sqlite3_exec(db, createActivityLogTable, nullptr, nullptr, nullptr);
    sqlite3_exec(db, createNotificationsTable, nullptr, nullptr, nullptr);
    sqlite3_exec(db, createFileVersionsTable, nullptr, nullptr, nullptr);

    const char* createFileTagsTable = "CREATE TABLE IF NOT EXISTS file_tags (id INTEGER PRIMARY KEY, file_path TEXT, tag TEXT);";
    sqlite3_exec(db, createFileTagsTable, nullptr, nullptr, nullptr);

    const char* createCollaborationsTable = "CREATE TABLE IF NOT EXISTS collaborations (id INTEGER PRIMARY KEY, file_path TEXT, username TEXT);";
    sqlite3_exec(db, createCollaborationsTable, nullptr, nullptr, nullptr);

    const char* createRecommendationsTable = "CREATE TABLE IF NOT EXISTS recommendations (id INTEGER PRIMARY KEY, username TEXT, recommendation TEXT);";
    sqlite3_exec(db, createRecommendationsTable, nullptr, nullptr, nullptr);
}

DatabaseManager::~DatabaseManager() {
    sqlite3_close(db);
}

bool DatabaseManager::upvoteComment(int commentId) {
    const char* updateQuery = "UPDATE comments SET upvotes = upvotes + 1 WHERE id = ?;";
    sqlite3_stmt* stmt;
    sqlite3_prepare_v2(db, updateQuery, -1, &stmt, nullptr);
    sqlite3_bind_int(stmt, 1, commentId);

    if (sqlite3_step(stmt) == SQLITE_DONE) {
        sqlite3_finalize(stmt);
        return true;
    }

    sqlite3_finalize(stmt);
    return false;
}

bool DatabaseManager::downvoteComment(int commentId) {
    const char* updateQuery = "UPDATE comments SET downvotes = downvotes + 1 WHERE id = ?;";
    sqlite3_stmt* stmt;
    sqlite3_prepare_v2(db, updateQuery, -1, &stmt, nullptr);
    sqlite3_bind_int(stmt, 1, commentId);

    if (sqlite3_step(stmt) == SQLITE_DONE) {
        sqlite3_finalize(stmt);
        return true;
    }

    sqlite3_finalize(stmt);
    return false;
}

void DatabaseManager::viewSortedComments(int parentId, const std::string& sortBy) {
    std::string query = "SELECT id, comment, upvotes, downvotes FROM comments WHERE parent_id = ? ORDER BY ";
    if (sortBy == "popularity") {
        query += "(upvotes - downvotes) DESC";
    } else {
        query += "id ASC"; // Default to sorting by date
    }

    sqlite3_stmt* stmt;
    sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, nullptr);
    sqlite3_bind_int(stmt, 1, parentId);

    std::cout << "--- Comments ---" << std::endl;
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        int id = sqlite3_column_int(stmt, 0);
        const char* comment = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
        int upvotes = sqlite3_column_int(stmt, 2);
        int downvotes = sqlite3_column_int(stmt, 3);
        std::cout << "ID: " << id << ", Comment: " << comment << ", Upvotes: " << upvotes << ", Downvotes: " << downvotes << std::endl;
    }

    sqlite3_finalize(stmt);
}

bool DatabaseManager::addFileTag(const std::string& filePath, const std::string& tag) {
    const char* insertQuery = "INSERT INTO file_tags (file_path, tag) VALUES (?, ?);";
    sqlite3_stmt* stmt;
    sqlite3_prepare_v2(db, insertQuery, -1, &stmt, nullptr);
    sqlite3_bind_text(stmt, 1, filePath.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, tag.c_str(), -1, SQLITE_STATIC);

    if (sqlite3_step(stmt) == SQLITE_DONE) {
        sqlite3_finalize(stmt);
        return true;
    }

    sqlite3_finalize(stmt);
    return false;
}

std::vector<std::string> DatabaseManager::getFileTags(const std::string& filePath) {
    const char* selectQuery = "SELECT tag FROM file_tags WHERE file_path = ?;";
    sqlite3_stmt* stmt;
    sqlite3_prepare_v2(db, selectQuery, -1, &stmt, nullptr);
    sqlite3_bind_text(stmt, 1, filePath.c_str(), -1, SQLITE_STATIC);

    std::vector<std::string> tags;
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        const char* tag = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
        tags.push_back(tag);
    }

    sqlite3_finalize(stmt);
    return tags;
}