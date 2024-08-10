#ifndef __COMMAND_FACTORY_H_
#define __COMMAND_FACTORY_H_

#include "Command.h"

class CommandFactory {
private:

public:
    CommandFactory() {}

    std::unique_ptr<Command> createCommand(const std::string& commandStr) const ;
};

#endif