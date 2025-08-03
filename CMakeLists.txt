cmake_minimum_required(VERSION 3.10)
project(ModularApp)

set(CMAKE_CXX_STANDARD 17)

# Add source files
add_executable(ModularApp 
    src/main.cpp
    src/auth/AuthManager.cpp
    src/comments/CommentManager.cpp
    src/database/DatabaseManager.cpp
    src/frontend/Frontend.cpp
    src/utils/FileUtils.cpp
)

# Link libraries (if needed)
find_package(SQLite3 REQUIRED)
target_link_libraries(ModularApp SQLite::SQLite3)