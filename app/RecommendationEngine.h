#ifndef RECOMMENDATION_ENGINE_H
#define RECOMMENDATION_ENGINE_H

#include "DatabaseManager.h"

class RecommendationEngine {
private:
    DatabaseManager& dbManager;

public:
    RecommendationEngine(DatabaseManager& dbManager);

    void generateFileRecommendations(const std::string& username);
    void generateTagRecommendations(const std::string& username);
    void generateCollaboratorRecommendations(const std::string& username);
};

#endif