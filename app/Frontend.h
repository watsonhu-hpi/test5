#ifndef FRONTEND_H
#define FRONTEND_H

#include "AuthManager.h"
#include "CommentManager.h"
#include "DatabaseManager.h"
#include <string>

class Frontend {
private:
    AuthManager authManager;
    CommentManager commentManager;
    DatabaseManager databaseManager;

    void login();
    void registerUser();
    void submitComment();
    void uploadFile();
    void viewItems();
    void editItem();
    void deleteItem();
    void logout();

public:
    Frontend(const std::string& dbPath);
    void renderHomePage();
};

#endif