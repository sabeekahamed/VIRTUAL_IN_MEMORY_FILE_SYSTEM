#include "FileSystem.h"
#include <iostream>
#include <algorithm>

std::string FileSystemObject::getName() const { 
	return name; 
}
void FileSystemObject::setParent(std::shared_ptr<Directory> parentDir) {
	parent = parentDir; 
}
std::shared_ptr<Directory> FileSystemObject::getParent() const {
	return parent.lock(); 
}

void File::write(const std::string & data) { 
	content = data; 
}
void File::append(const std::string & data) { 
	content += data; 
}
std::string File::read() const {
	return content; 
}
void File::ls() const {
    std::cout << getName() << std::endl;
}



void Directory::add(const std::shared_ptr<FileSystemObject>& obj) {
    children[obj->getName()] = obj;

    std::shared_ptr<Directory> self = std::dynamic_pointer_cast<Directory>(shared_from_this());
    if (self) {
        obj->setParent(self);  // Sets the parent as this directory
    }
    else {
        throw std::runtime_error("Parent directory casting failed.");
    }

}

std::shared_ptr<FileSystemObject> Directory::get(const std::string& name) {
    if (children.find(name) != children.end())
        return children[name];
    else
        throw FileNotFoundException("File or directory not found: " + name);
}

void Directory::ls() const  {
    const auto& curChildren = FileSystem::getInstance()->getCurrentDirectory()->children;
    for (const auto& child : curChildren) {
        std::cout << child.first << std::endl;
    }
}

void Directory::removeDir(const std::string& name) {
    auto dir = std::dynamic_pointer_cast<Directory>(find(name));
    if (!dir) {
        throw std::runtime_error("Directory not found");
    }
    if (!dir->children.empty()) {
        throw std::runtime_error("Directory not empty");
    }
    children.erase(name);
}

void Directory::removeFile(const std::string& name) {
    auto file = std::dynamic_pointer_cast<File>(find(name));
    if (!file) {
        throw std::runtime_error("File not found");
    }
    children.erase(name);
}
void Directory::remove(const std::string& name) {
    auto currentDir = FileSystem::getInstance()->getCurrentDirectory();
    if (std::dynamic_pointer_cast<File>(currentDir->find(name))) {
        currentDir->removeFile(name);
    } else if (std::dynamic_pointer_cast<Directory>(currentDir->find(name))) {
        currentDir->removeDir(name);
    } else {
        throw std::runtime_error("File or Directory not found");
    }
}

bool Directory::isEmpty() const {
    return children.empty();
}

std::shared_ptr<FileSystemObject> Directory::find(const std::string& name) const {
    auto it = std::find_if(children.begin(), children.end(),
        [&name](const std::pair<const std::string, std::shared_ptr<FileSystemObject>>& pair) {
            return pair.second->getName() == name;
        });

    if (it != children.end()) {
        return it->second;
    }
    return nullptr;
}


//-------------------------------------------------------------//
FileSystem::FileSystem() {
    root = std::make_shared<Directory>("root");
    currentDirectory = root;
}

FileSystem* FileSystem::getInstance() {
    if (!instance)
        instance = new FileSystem();
    return instance;
}

std::shared_ptr<Directory> FileSystem::getRoot() { 
    return root; 
}
std::shared_ptr<Directory> FileSystem::getCurrentDirectory() { 
    return currentDirectory; 
}
void FileSystem::setCurrentDirectory(std::shared_ptr<Directory> dir) { 
    currentDirectory = std::move(dir); 
}

std::string FileSystem::getCurrentPath() {
    std::shared_ptr<Directory> dir = currentDirectory;
    std::string path = "";
    while (dir) {
        path = "/" + dir->getName() + path;
        if (dir == root) break;
        dir = std::dynamic_pointer_cast<Directory>(dir->getParent());
    }
    return path;
}

FileSystem* FileSystem::instance = nullptr;
//----------------------------------------------------//