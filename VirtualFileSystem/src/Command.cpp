#include<iostream>
#include "VirtualFullHandler.h"
#include "FileSystemException.h"
#include "Command.h"
#include "FileSystem.h"

void LsCommand::execute() {
    try {
        FileSystem::getInstance()->getCurrentDirectory()->ls();
    }
    catch (const FileSystemException& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

void PwdCommand::execute()  {
    try {
        std::cout << FileSystem::getInstance()->getCurrentPath() << std::endl;
    }
    catch (const FileSystemException& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

TouchCommand::TouchCommand(const std::string& name)
        :  filename(name) {}

void TouchCommand::execute()  {
        if (FileSystem::getInstance()->getCurrentDirectory()->find(filename)) {
            throw std::runtime_error("File already exists");
        }
        FileSystem::getInstance()->getCurrentDirectory()->add(std::make_shared<File>(filename));
        std::cout << "File created: " << filename << std::endl;
}

MkdirCommand::MkdirCommand(const std::string& name)
        :  dirname(name) {}

void MkdirCommand::execute()  {
        if (FileSystem::getInstance()->getCurrentDirectory()->find(dirname)) {
            throw std::runtime_error("Directory already exists");
        }
        FileSystem::getInstance()->getCurrentDirectory()->add(std::make_shared<Directory>(dirname));
        std::cout << "Directory created: " << dirname << std::endl;
}

CdCommand::CdCommand( const std::string& name)
        :  dirname(name) {}

void CdCommand::execute()  {
        if (dirname == "..") {
            std::shared_ptr<Directory> dir = std::dynamic_pointer_cast<Directory>(FileSystem::getInstance()->getCurrentDirectory()->getParent());
            if (!dir) {
                throw std::runtime_error("Already in root.");
            }
            FileSystem::getInstance()->setCurrentDirectory(dir);
            std::cout << "Changed directory to: " << dirname << std::endl;
        

        } else {
            std::shared_ptr<Directory> dir = std::dynamic_pointer_cast<Directory>(FileSystem::getInstance()->getCurrentDirectory()->find(dirname));
            if (!dir) {
                throw std::runtime_error("Directory not found");
            }
            FileSystem::getInstance()->setCurrentDirectory(dir);
            std::cout << "Changed directory to: " << FileSystem::getInstance()->getCurrentDirectory()->getName() << std::endl;
        }
    }


RmCommand::RmCommand(const std::string& name):  dirname(name) {}
void RmCommand::execute(){
    FileSystem::getInstance()->getCurrentDirectory()->remove(dirname);
}

//=============ToDO================
CatCommand::CatCommand(const std::string&fName):fileName(fName){};
void CatCommand::execute() {
    auto file = std::dynamic_pointer_cast<File>(FileSystem::getInstance()->getCurrentDirectory()->find(fileName));
    if (!file) {
        throw std::runtime_error("File not found");
    }
    std::cout<<file->read();
}

WriteCommmand::WriteCommmand(const std::string&name,const std::string&cont):fName(name),tmpContent(cont){
}
void WriteCommmand::execute(){
    auto file = std::dynamic_pointer_cast<File>(FileSystem::getInstance()->getCurrentDirectory()->find(fName));
    if (!file) {
        throw std::runtime_error("File not found");
    }
    file->write(tmpContent);
}

AppendCommand::AppendCommand(const std::string&name,const std::string&cont):fName(name),tmpContent(cont){
}
void AppendCommand::execute(){
    auto file = std::dynamic_pointer_cast<File>(FileSystem::getInstance()->getCurrentDirectory()->find(fName));
    if (!file) {
        throw std::runtime_error("File not found");
    }
    file->append(tmpContent);
}