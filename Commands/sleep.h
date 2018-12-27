//
// Created by shilo on 12/16/18.
//

#ifndef FLIGHT_SIMULATOR_SLEEP_H
#define FLIGHT_SIMULATOR_SLEEP_H

#include "Command.h"
#include "sleep.h"


class Sleep : public Command {
    Expression *a;
public:
    Sleep(Expression *_a);
    void execute();
    ~Sleep();
};


#endif //FLIGHT_SIMULATOR_SLEEP_H
