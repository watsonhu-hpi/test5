#ifndef DATABASE_MANAGER_H
#define DATABASE_MANAGER_H

#include <string>
#include <sqlite3.h>
#include <map>

#include <vector>
#include <string>

class DatabaseManager {
private:
    sqlite3* db;

    std::string getMostActiveUser();
    std::string getMostCommentedTopic();
    std::map<std::string, int> generateUserActivityHeatmap();

public:
    DatabaseManager(const std::string& dbPath);
    ~DatabaseManager();

    bool addFileTag(const std::string& filePath, const std::string& tag);
    std::vector<std::string> getFileTags(const std::string& filePath);

    int getTotalUsers();
    int getTotalComments();
    int getTotalFiles();

    bool addFileCategory(int commentId, const std::string& category);
    void getFilesByCategory(const std::string& category);
    void searchComments(const std::string& keyword);

    std::string analyzeSentiment(const std::string& comment);
    bool storeSentiment(int commentId, const std::string& sentiment);
    void displaySentiments();

    bool logActivity(int userId, const std::string& action);
    void viewActivityLog();

    void displayEnhancedAnalytics();
    void displayAdminDashboard();

    bool sendNotification(int userId, const std::string& message);
    void viewNotifications(int userId);
    bool markNotificationAsRead(int notificationId);

    void startRealTimeNotificationSystem(int userId);

    bool addFileVersion(int fileId, const std::string& filePath);
    void viewFileVersions(int fileId);
    bool restoreFileVersion(int fileId, int version, std::string& restoredFilePath);

    bool addComment(const std::string& comment, int parentId);
    void viewCommentThread(int parentId, int depth);

    bool updateUserRole(int userId, const std::string& newRole);
    void viewAllUsers();

    bool upvoteComment(int commentId);
    bool downvoteComment(int commentId);
    void viewSortedComments(int parentId, const std::string& sortBy);

    bool createItem(const std::string& itemName);
    void readItems();
    bool updateItem(int itemId, const std::string& newItemName);
    bool deleteItem(int itemId);
};

#endif