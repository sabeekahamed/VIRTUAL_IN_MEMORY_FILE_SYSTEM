#ifndef __COMMAND_INVOKER_H_
#define __COMMAND_INVOKER_H_

#include "Command.h"

class CommandInvoker {
private:
    std::unique_ptr<Command> command;

public:
    void setCommand(std::unique_ptr<Command> &cmd) ;

    void executeCommand() ;
};
#endif
