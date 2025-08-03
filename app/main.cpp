#include "frontend/Frontend.h"
#include <iostream>

int main() {
    const std::string dbPath = "database/app.db";

    std::cout << "Starting the Modular C++ Application..." << std::endl;

    Frontend frontend(dbPath);
    frontend.renderHomePage();

    std::cout << "Exiting the application. Goodbye!" << std::endl;
    return 0;
}