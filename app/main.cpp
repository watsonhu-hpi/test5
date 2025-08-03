#include "frontend/Frontend.h"
#include <iostream>
#include "DatabaseManager.h"
#include "FileManager.h"
#include "CollaborationManager.h"
#include "AnalyticsManager.h"
#include "RecommendationEngine.h"

int main() {
    const std::string dbPath = "database/app.db";

    std::cout << "Starting the Modular C++ Application..." << std::endl;

    DatabaseManager dbManager(dbPath);
    FileManager fileManager(dbManager);
    CollaborationManager collaborationManager(dbManager);
    AnalyticsManager analyticsManager(dbManager);
    RecommendationEngine recommendationEngine(dbManager);
    // Demonstrate FileManager usage
    fileManager.saveFile("example.txt");
    fileManager.addTag("example.txt", "important");

    // Demonstrate CollaborationManager usage
    collaborationManager.addCollaborator("example.txt", "user1");
    collaborationManager.listCollaborators("example.txt");

    // Demonstrate AnalyticsManager usage
    analyticsManager.generateUserActivityHeatmap();
    analyticsManager.generateFileUsageTrends();

    // Demonstrate RecommendationEngine usage
    recommendationEngine.generateFileRecommendations("user1");

    std::cout << "Exiting the application. Goodbye!" << std::endl;
    return 0;
}