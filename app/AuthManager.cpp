#include "AuthManager.h"
#include <iostream>
#include <sqlite3.h>
#include <string>

AuthManager::AuthManager(const std::string& dbPath) {
    sqlite3_open(dbPath.c_str(), &db);
    const char* createTableQuery = "CREATE TABLE IF NOT EXISTS users (id INTEGER PRIMARY KEY, username TEXT UNIQUE, password TEXT, role TEXT);";
    sqlite3_exec(db, createTableQuery, nullptr, nullptr, nullptr);
}

AuthManager::~AuthManager() {
    sqlite3_close(db);
}

bool AuthManager::registerUser(const std::string& username, const std::string& password, const std::string& role) {
    const char* insertQuery = "INSERT INTO users (username, password, role) VALUES (?, ?, ?);";
    sqlite3_stmt* stmt;
    sqlite3_prepare_v2(db, insertQuery, -1, &stmt, nullptr);
    sqlite3_bind_text(stmt, 1, username.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, password.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, role.c_str(), -1, SQLITE_STATIC);

    if (sqlite3_step(stmt) == SQLITE_DONE) {
        sqlite3_finalize(stmt);
        return true;
    }

    sqlite3_finalize(stmt);
    return false;
}

bool AuthManager::login(const std::string& username, const std::string& password, std::string& role) {
    const char* selectQuery = "SELECT role FROM users WHERE username = ? AND password = ?;";
    sqlite3_stmt* stmt;
    sqlite3_prepare_v2(db, selectQuery, -1, &stmt, nullptr);
    sqlite3_bind_text(stmt, 1, username.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, password.c_str(), -1, SQLITE_STATIC);

    if (sqlite3_step(stmt) == SQLITE_ROW) {
        role = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
        sqlite3_finalize(stmt);
        return true;
    }

    sqlite3_finalize(stmt);
    return false;
}

void AuthManager::logout() {
    std::cout << "User logged out successfully." << std::endl;
}