//
// Created by shilo on 12/16/18.
//

#include "if_command.h"

void If::execute()
{
    // If condition applies, execute all commands in sequence
    if (conditionTrue()) {
        for (Command* command : commands) {
            command->execute();
        }
    }
}