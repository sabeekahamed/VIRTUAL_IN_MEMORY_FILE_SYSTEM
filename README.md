                            **Virtual File System (VFS) Implementation**
                            
Problem Statement and Requirements Document
1. Overview
 Development of Virtual File System (VFS) in C++ that simulates a hierarchical file structure in
memory. The VFS should provide an interface like a basic Unix-like file system, allowing users to
perform common file and directory operations.
2. Objectives
 2.1. Create a robust, in-memory file system simulation.
 2.2. Implement a user-friendly command-line interface for system interaction.
 2.3. Demonstrate proficiency in C++ programming and software design principles.
3. Detailed Requirements
 3.1. File and Directory Structure
 3.1.1. Implement a hierarchical structure of files and directories.
 3.1.2. Files should store content as a string or byte array.
 3.1.3. Directories should be able to contain both files and other directories.
 3.2. Core Operations
 3.2.1. File Operations:
 - Create a new file
 - Read file contents
 - Write to a file (overwrite and append modes)
 - Delete a file
 3.2.2. Directory Operations:
 - Create a new directory
 - Delete a directory (only if empty)
 - List contents of a directory
 3.2.3. File System Operations:
 - Move files or directories
 - Copy files or directories
 - Rename files or directories
 3.3. Path Handling
 3.3.1. Implement absolute and relative path resolution.
 3.3.2. Handle '..' (parent directory) and '.' (current directory) in paths.
 3.3.3. Maintain a concept of "current working directory".
 3.3.4. Allow changing the current directory.
 3.4. Error Handling
 3.4.1. Implement comprehensive error checking for all operations.
 3.4.2. Provide meaningful error messages for various scenarios (e.g., file not found,
directory not empty, permission denied).
 3.5. Memory Management
 3.5.1. Ensure proper memory management to prevent leaks.
 3.5.2. Implement a basic garbage collection or reference counting system.
 3.6. Command-Line Interface
 3.6.1. Create a simple CLI to interact with the virtual file system.
 3.6.2. Support the following commands:
 - ls: List directory contents
 - cd: Change current directory
 - mkdir: Create a new directory
 - touch: Create a new file
 - rm: Remove a file or empty directory
 - mv: Move or rename a file or directory
 - cp: Copy a file or directory
 - cat: Display file contents
 - pwd: Print working directory
 - help: Display available commands and their usage
 3.7. Design Patterns
 3.7.1. Utilize at least three appropriate design patterns in the implementation. Suggested
patterns include:
 - Composite Pattern for file/directory hierarchy
 - Command Pattern for CLI operations
 - Singleton Pattern for file system instance
 - Factory Pattern for creating file system objects
 - Observer Pattern for file system change notifications
 3.8. Unit Testing
 3.8.1. Implement comprehensive unit tests for all major components and operations.
 3.8.2. Achieve at least 80% code coverage with unit tests.
 3.8.3. Include edge cases and error scenarios in the test suite.
4. Deliverables
 4.1. C++ source code implementing the VFS.
 4.2. A command-line interface application to interact with the VFS.
 4.3. Comprehensive unit test suite.
 4.4. README file with:
 4.4.1. Instructions for compiling and running the application
 4.4.2. Overview of the system architecture and design patterns used
 4.4.3. List of implemented features and any known limitations
 4.5. Brief technical documentation explaining key design decisions and class structure.
5. Evaluation Criteria
 5.1. Code quality, readability, and organization
 5.2. Proper use of C++ features and standard library
 5.3. Correct implementation of required functionality
 5.4. Efficiency of file and directory operations
 5.5. Robustness of error handling
 5.6. Effectiveness of memory management
 5.7. Appropriate use of design patterns
 5.8. Usability of the command-line interface
 5.9. Thoroughness and pass rate of unit tests
 5.10. Clarity and completeness of documentation
6. Constraints
 6.1. Use only standard C++ libraries; no external libraries for core functionality.
