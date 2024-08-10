#include "CommandFactory.h"
#include <iostream>
#include <sstream>


std::unique_ptr<Command> CommandFactory::createCommand(const std::string& commandStr) const {
        std::istringstream iss(commandStr);
        std::string command;
        std::string argument;
        iss >> command;
        std::getline(iss, argument); // Get the argument (if any)
        if (command == "touch") {
            return std::make_unique<TouchCommand>( argument);
        } else if (command == "mkdir") {
            return std::make_unique<MkdirCommand>( argument);
        } else if (command == "cd") {
            return std::make_unique<CdCommand>( argument);
        }else if(command == "pwd"){
            return std::make_unique<PwdCommand>();
        }else if(command == "rm"){
            //return std::make
        }else if(command == "cat"){
            return std::make_unique<CatCommand>(argument);
        }else if(command == "ls"){
            return std::make_unique<LsCommand>();
        }else if(command == "write"){
            return std::make_unique<WriteCommmand>(argument);
        }else if(command == "append"){
            return std::make_unique<AppendCommand>(argument);
        }else if(command == ""){
            
        }else if(command == ""){
            
        }
        
        
        else {
            std::cerr << "Unknown command: " << command << std::endl;
            return nullptr;
        }
    }