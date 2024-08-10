#ifndef __FILE_SYSTEM_H_
#define __FILE_SYSTEM_H_


//#include<iostream>
#include<memory>
#include<unordered_map>
#include "FileSystemException.h"

class Directory;
// Base class for FileSystem objects
class FileSystemObject : public std::enable_shared_from_this<FileSystemObject> {
protected:
    std::string name;
    std::weak_ptr<Directory> parent;

public:
    FileSystemObject(const std::string& name) : name(name) {}
    virtual ~FileSystemObject() = default;
    std::string getName() const;
    void setParent(std::shared_ptr<Directory> parentDir);
    std::shared_ptr<Directory> getParent() const;
    virtual void ls() const = 0;
};

class File : public FileSystemObject {
private:
    std::string content;

public:
    File(const std::string& name) : FileSystemObject(name), content("") {}
    void write(const std::string& data);
    std::string read() const;
    void append(const std::string & data);
    void ls() const override;
};

class Directory : public FileSystemObject {
private:
    std::unordered_map<std::string, std::shared_ptr<FileSystemObject>> children;
    void removeFile(const std::string& name);
    void removeDir(const std::string& name);
public:
    Directory(const std::string& name) : FileSystemObject(name) {}

    void add(const std::shared_ptr<FileSystemObject>& obj);

    std::shared_ptr<FileSystemObject> get(const std::string& name);

    void ls() const override;

    void remove(const std::string& name);

    std::shared_ptr<FileSystemObject> find(const std::string&fname) const;
    
    bool isEmpty() const;
};

// Singleton class for FileSystem
class FileSystem {
private:
    static FileSystem* instance;
    std::shared_ptr<Directory> root;
    std::shared_ptr<Directory> currentDirectory;

    FileSystem();

public:
    static FileSystem* getInstance();

    std::shared_ptr<Directory> getRoot();
    std::shared_ptr<Directory> getCurrentDirectory();
    void setCurrentDirectory(std::shared_ptr<Directory> dir);

    std::string getCurrentPath();
};

#endif