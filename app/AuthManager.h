#ifndef AUTH_MANAGER_H
#define AUTH_MANAGER_H

#include <string>
#include <sqlite3.h>

class AuthManager {
private:
    sqlite3* db;

public:
    AuthManager(const std::string& dbPath);
    ~AuthManager();

    bool registerUser(const std::string& username, const std::string& password, const std::string& role);
    bool login(const std::string& username, const std::string& password, std::string& role);
    void logout();
};

#endif