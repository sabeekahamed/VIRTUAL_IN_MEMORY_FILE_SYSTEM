#ifndef __FILE_SYSTEM_EXP_H_
#define __FILE_SYSTEM_EXP_H_
#include <stdexcept>

// Custom exceptions for error handling
class FileSystemException : public std::runtime_error {
public:
    explicit FileSystemException(const std::string& message) : std::runtime_error(message) {}
};

class FileNotFoundException : public FileSystemException {
public:
    explicit FileNotFoundException(const std::string& message) : FileSystemException(message) {}
};

class DirectoryNotEmptyException : public FileSystemException {
public:
    explicit DirectoryNotEmptyException(const std::string& message) : FileSystemException(message) {}
};

#endif