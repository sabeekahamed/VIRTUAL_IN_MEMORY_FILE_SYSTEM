#ifndef __COMMAND_H_
#define __COMMAND_H_
#include "FileSystem.h"

/*
3.2. Core Operations
3.2.1. File Operations:
- Create a new file
- Read file contents
- Write to a file (overwrite and append modes)
- Delete a file
3.2.2. Directory Operations:
- Create a new directory
- Delete a directory (only if empty)
- List contents of a directory3.2.3. File System Operations:
- Move files or directories
- Copy files or directories
- Rename files or directories
*/



// Command Pattern
class Command {
public:
    virtual void execute() = 0;
};

class LsCommand : public Command {
public:
    void execute() override;
};

class PwdCommand : public Command {
public:
    void execute() override;
};

class TouchCommand : public Command {
private:
    std::string filename;

public:
    TouchCommand( const std::string& name);
    void execute() override ;
};


class MkdirCommand : public Command {
private:
    std::string dirname;

public:
    MkdirCommand( const std::string& name);
    void execute() override ;
};

class CdCommand : public Command {
private:
    std::string dirname;

public:
    CdCommand(const std::string& name);
    void execute() override ;
};


class RmCommand : public Command {
private:
    std::string dirname;

public:
    RmCommand( const std::string& name);
    void execute() override ;
};

class CatCommand : public Command{
    private:
    std::string fileName;
    public:
    CatCommand(const std::string&fName);
    void execute() override ;
};

class WriteCommmand:public Command{
    private:
    std::string fName;
    std::string tmpContent;
    public:
    WriteCommmand(const std::string&name,const std::string&cont);
    void execute()override;
};

class AppendCommand:public Command{
    private:
    std::string tmpContent;
    std::string fName;
    public:
    AppendCommand(const std::string&name,const std::string&cont);
    void execute()override;
};

/* * /

class PwdCommand : public Command {
public:
    void execute() override;
};

class PwdCommand : public Command {
public:
    void execute() override;
};

class PwdCommand : public Command {
public:
    void execute() override;
};

class PwdCommand : public Command {
public:
    void execute() override;
};

class PwdCommand : public Command {
public:
    void execute() override;
};

class PwdCommand : public Command {
public:
    void execute() override;
};

class PwdCommand : public Command {
public:
    void execute() override;
};

class PwdCommand : public Command {
public:
    void execute() override;
};
*/


#endif