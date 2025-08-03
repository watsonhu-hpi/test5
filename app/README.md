# Modular C++ Application

## Features
- User login and authentication
- Comment submission and file uploads
- Database querying and updating
- Local testing support

## File Structure
```
project/
├── src/
│   ├── main.cpp                # Entry point
│   ├── auth/
│   │   ├── AuthManager.cpp      # Authentication logic
│   │   ├── AuthManager.h
│   ├── comments/
│   │   ├── CommentManager.cpp   # Comment and file upload logic
│   │   ├── CommentManager.h
│   ├── database/
│   │   ├── DatabaseManager.cpp  # Database interaction logic
│   │   ├── DatabaseManager.h
│   ├── frontend/
│   │   ├── Frontend.cpp         # Frontend rendering logic
│   │   ├── Frontend.h
│   ├── utils/
│   │   ├── FileUtils.cpp        # File handling utilities
│   │   ├── FileUtils.h
│   ├── config.h                 # Configuration constants
├── public/                      # Frontend assets
│   ├── index.html
│   ├── styles.css
│   ├── app.js
├── database/
│   ├── app.db                   # SQLite database
├── CMakeLists.txt               # Build configuration
├── README.md                    # Documentation
```

## Build and Run
1. Install CMake and a C++ compiler.
2. Run the following commands:
   ```
   mkdir build
   cd build
   cmake ..
   make
   ./ModularApp
   ```