#ifndef ANALYTICS_MANAGER_H
#define ANALYTICS_MANAGER_H

#include "DatabaseManager.h"

class AnalyticsManager {
private:
    DatabaseManager& dbManager;

public:
    AnalyticsManager(DatabaseManager& dbManager);

    void generateUserActivityHeatmap();
    void generateFileUsageTrends();
    void performSentimentAnalysis();
};

#endif