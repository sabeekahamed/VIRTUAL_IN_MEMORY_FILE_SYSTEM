#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <unordered_map>
#include <stdexcept>
#include <sstream>
//#include "VirtualFullHandler.h"
#include "FileSystemException.h"
#include "Command.h"
#include "FileSystem.h"
#include "CommandFactory.h"
#include "CommandInvoker.h"

// Path Resolution Helper Functions
std::shared_ptr<FileSystemObject> resolvePath(const std::string& path) {
    auto fs = FileSystem::getInstance();
    std::shared_ptr<Directory> currentDir = fs->getCurrentDirectory();
    std::vector<std::string> parts;
    std::stringstream ss(path);
    std::string part;

    while (std::getline(ss, part, '/')) {
        if (!part.empty()) {
            parts.push_back(part);
        }
    }

    for (const auto& part : parts) {
        if (part == "..") {
            if (currentDir->getParent()) {
                currentDir = std::dynamic_pointer_cast<Directory>(currentDir->getParent());
            }
        }
        else if (part != ".") {
            currentDir = std::dynamic_pointer_cast<Directory>(currentDir->get(part));
        }
    }
    return currentDir;
}

// Main CLI loop
void CLI() {
    std::string commandStr;
    CommandFactory cmdFactory;
    CommandInvoker cmdInvoker;
    while (true) {
        std::cout << "> ";

          try {
            std::getline(std::cin, commandStr);
            if (commandStr.rfind("exit", 0) == 0) {
                std::cout<<"Shutting down the file system...";
                break;
            }

            std::unique_ptr<Command>commandObj = cmdFactory.createCommand(commandStr);
            cmdInvoker.setCommand(commandObj);
            cmdInvoker.executeCommand();
            continue;

            
            if (commandStr.rfind("touch", 0) == 0) {
                std::string filename = commandStr.substr(6);
                TouchCommand touchCmd( filename);
                touchCmd.execute();
            } else if (commandStr.rfind("mkdir", 0) == 0) {
                std::string dirname = commandStr.substr(6);
                MkdirCommand mkdirCmd(dirname);
                mkdirCmd.execute();
            } else if (commandStr.rfind("rm", 0) == 0) {
                std::string name = commandStr.substr(3);
                RmCommand rmCmd( name);
                rmCmd.execute();
            } else if (commandStr.rfind("cat", 0) == 0) {
                std::string name = commandStr.substr(3);
                RmCommand rmCmd( name);
                rmCmd.execute();
            } else if (commandStr == "ls") {
                LsCommand lsCmd;
                lsCmd.execute();
            } else if (commandStr.rfind("cd", 0) == 0) {
                std::string dirname = commandStr.substr(3);
                CdCommand cdCmd( dirname);
                cdCmd.execute();
            } else if (commandStr == "exit") {
                break;
            } else {
                std::cout << "Unknown commandStr: " << commandStr << std::endl;
            }
        } catch (const std::exception& e) {
            std::cout << "Error: " << e.what() << std::endl;
        }
    }
}

int main() {
    CLI();
    return 0;
}






/* * /
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <unordered_map>
#include <stdexcept>


// Base class for FileSystem objects
class FileSystemObject {
protected:
    std::string name;
public:
    FileSystemObject(const std::string& name) : name(name) {}
    virtual ~FileSystemObject() = default;
    std::string getName() const { return name; }
    virtual void ls() const = 0; // Pure virtual function for listing
};

class File : public FileSystemObject {
private:
    std::string content;
public:
    File(const std::string& name) : FileSystemObject(name), content("") {}
    void write(const std::string& data) { content += data; }
    std::string read() const { return content; }
    void ls() const override {
        std::cout << getName() << std::endl;
    }
};

class Directory : public FileSystemObject {
private:
    std::unordered_map<std::string, std::shared_ptr<FileSystemObject>> children;
public:
    Directory(const std::string& name) : FileSystemObject(name) {}
    void add(const std::shared_ptr<FileSystemObject>& obj) {
        children[obj->getName()] = obj;
    }
    std::shared_ptr<FileSystemObject> get(const std::string& name) {
        if (children.find(name) != children.end())
            return children[name];
        else
            throw std::runtime_error("File or directory not found");
    }
    void ls() const override {
        for (const auto& child : children) {
            std::cout << child.first << std::endl;
        }
    }
};



// Singleton class for FileSystem
class FileSystem {
private:
    static FileSystem* instance;
    std::shared_ptr<Directory> root;
    std::shared_ptr<Directory> currentDirectory;

    FileSystem() {
        root = std::make_shared<Directory>("root");
        currentDirectory = root;
    }

public:
    static FileSystem* getInstance() {
        if (!instance)
            instance = new FileSystem();
        return instance;
    }

    std::shared_ptr<Directory> getRoot() { return root; }
    std::shared_ptr<Directory> getCurrentDirectory() { return currentDirectory; }
    void setCurrentDirectory(std::shared_ptr<Directory> dir) { currentDirectory = dir; }
};

FileSystem* FileSystem::instance = nullptr;


// CLI and Command Pattern
class Command {
public:
    virtual void execute() = 0;
};

class LsCommand : public Command {
public:
    void execute() override {
        FileSystem::getInstance()->getCurrentDirectory()->ls();
    }
};

// Main CLI loop
void CLI() {
    std::string input;
    while (true) {
        std::cout << "> ";
        std::getline(std::cin, input);
        if (input == "ls") {
            LsCommand cmd;
            cmd.execute();
        }
        else if (input == "exit") {
            break;
        }
        else {
            std::cout << "Unknown commandStr" << std::endl;
        }
    }
}

int main() {
    CLI();
    return 0;
}
*/