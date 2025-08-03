#include "Frontend.h"
#include "AuthManager.h"
#include "CommentManager.h"
#include "DatabaseManager.h"
#include <iostream>

Frontend::Frontend(const std::string& dbPath)
    : authManager(dbPath), commentManager(dbPath), databaseManager(dbPath) {}

void Frontend::renderHomePage() {
    std::cout << "Welcome to the Modular App!" << std::endl;
    std::cout << "1. Login\n2. Register\n3. View Analytics\n4. Categorize File\n5. View Files by Category\n6. Search Comments\n7. Analyze Comment Sentiment\n8. Display Sentiments\n9. View Activity Log\n10. View Enhanced Analytics\n11. View Notifications\n12. Manage File Versions\n13. Comment Threads\n14. Admin Dashboard\n15. Manage User Roles\n16. Start Real-Time Notifications\n17. Exit" << std::endl;

    int choice;
    while (true) {
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            login();
            break;
        case 2:
            registerUser();
            break;
        case 3:
            viewAnalytics();
            break;
        case 4:
            categorizeFile();
            break;
        case 5:
            viewFilesByCategory();
            break;
        case 6:
            searchComments();
            break;
        case 7:
            analyzeCommentSentiment();
            break;
        case 8:
            displaySentiments();
            break;
        case 9:
            viewActivityLog();
            break;
        case 10:
            viewEnhancedAnalytics();
            break;
        case 11:
            viewNotifications();
            break;
        case 12:
            manageFileVersions();
            break;
        case 13:
            manageCommentThreads();
            break;
        case 14:
            viewAdminDashboard();
            break;
        case 15:
            manageUserRoles();
            break;
        case 16:
            startRealTimeNotifications();
            break;
        case 17:
            return;
        default:
            std::cout << "Invalid choice. Try again." << std::endl;
        }
    }
}

void Frontend::manageCommentThreads() {
    int parentId;
    std::cout << "Enter the ID of the parent comment (or 0 for a new thread): ";
    std::cin >> parentId;

    int choice;
    std::cout << "1. Add Comment\n2. View Thread\n3. Upvote Comment\n4. Downvote Comment\n5. View Sorted Comments\nEnter your choice: ";
    std::cin >> choice;

    switch (choice) {
    case 1: {
        std::string comment;
        std::cout << "Enter your comment: ";
        std::cin.ignore();
        std::getline(std::cin, comment);

        if (databaseManager.addComment(comment, parentId)) {
            std::cout << "Comment added successfully!" << std::endl;
        } else {
            std::cout << "Failed to add comment." << std::endl;
        }
        break;
    }
    case 2:
        databaseManager.viewCommentThread(parentId, 0);
        break;
    case 3: {
        int commentId;
        std::cout << "Enter the ID of the comment to upvote: ";
        std::cin >> commentId;

        if (databaseManager.upvoteComment(commentId)) {
            std::cout << "Comment upvoted successfully!" << std::endl;
        } else {
            std::cout << "Failed to upvote comment." << std::endl;
        }
        break;
    }
    case 4: {
        int commentId;
        std::cout << "Enter the ID of the comment to downvote: ";
        std::cin >> commentId;

        if (databaseManager.downvoteComment(commentId)) {
            std::cout << "Comment downvoted successfully!" << std::endl;
        } else {
            std::cout << "Failed to downvote comment." << std::endl;
        }
        break;
    }
    case 5: {
        std::string sortBy;
        std::cout << "Enter sorting method (popularity/date): ";
        std::cin >> sortBy;

        databaseManager.viewSortedComments(parentId, sortBy);
        break;
    }
    default:
        std::cout << "Invalid choice." << std::endl;
    }
}