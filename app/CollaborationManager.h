#ifndef COLLABORATION_MANAGER_H
#define COLLABORATION_MANAGER_H

#include <string>
#include "DatabaseManager.h"

class CollaborationManager {
private:
    DatabaseManager& dbManager;

public:
    CollaborationManager(DatabaseManager& dbManager);

    void addCollaborator(const std::string& filePath, const std::string& username);
    void removeCollaborator(const std::string& filePath, const std::string& username);
    void listCollaborators(const std::string& filePath);
};

#endif