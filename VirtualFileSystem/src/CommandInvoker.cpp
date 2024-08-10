#include "CommandInvoker.h"
#include <iostream>

void CommandInvoker::setCommand(std::unique_ptr<Command> &cmd) {
        command = std::move(cmd);
}

void CommandInvoker::executeCommand() {
    if (command) {
        command->execute();
    } else {
        std::cerr << "No command set" << std::endl;
    }
}