#ifndef __COMMAND_BUILDER_H_
#define __COMMAND_BUILDER_H_

#include "Command.h"

class CommandBuilder {
public:
    virtual ~CommandBuilder() = default;
    virtual std::unique_ptr<Command> build() const = 0;
};

class TouchCommandBuilder : public CommandBuilder {
private:
public:
    std::unique_ptr<Command> build() const override {
        return std::make_unique<TouchCommand>();
    }
};


#endif