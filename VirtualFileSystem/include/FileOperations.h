#ifndef __FILE_OPERATIONS_H_
#define __FILE_OPERATIONS_H_

#include "FileSystem.h"
#include <memory>

class FileOperations{
    public:
    void touch(std::shared_ptr<Directory>& currentDir, const std::string& filename) {
        if (currentDir->find(filename)) {
            throw std::runtime_error("File already exists");
        }
        currentDir->add(std::make_shared<File>(filename));
    }
void mkdir(std::shared_ptr<Directory>& currentDir, const std::string& dirname) {
    if (currentDir->find(dirname)) {
        throw std::runtime_error("Directory already exists");
    }
    currentDir->add(std::make_shared<Directory>(dirname));
}
void rm(std::shared_ptr<Directory>& currentDir, const std::string& filename) {
    auto obj = currentDir->find(filename);
    if (!obj) {
        throw std::runtime_error("File not found");
    }
    currentDir->remove(filename);
}
/*
* /
void rmdir(std::shared_ptr<Directory>& currentDir, const std::string& dirname) {
    auto dir = std::dynamic_pointer_cast<Directory>(currentDir->find(dirname));
    if (!dir) {
        throw std::runtime_error("Directory not found");
    }
    if (!dir->children.empty()) {
        throw std::runtime_error("Directory is not empty");
    }
    currentDir->remove(dirname);
}
std::shared_ptr<Directory> cd(std::shared_ptr<Directory>& currentDir, const std::string& dirname) {
    if (dirname == "..") {
        // Assuming we have a way to move to the parent directory
    } else {
        auto dir = std::dynamic_pointer_cast<Directory>(currentDir->find(dirname));
        if (!dir) {
            throw std::runtime_error("Directory not found");
        }
        return dir;
    }
    return currentDir;
}
*/
};

#endif