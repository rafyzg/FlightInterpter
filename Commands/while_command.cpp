//
// Created by shilo on 12/16/18.
//

#include "while_command.h"

void While::execute()
{
    // if condition true, execute all commands in sequence and loop back
    while (conditionTrue()) {
        for (Command* command : commands) {
            command->execute();
        }
    }
}