//
// Created by shilo on 12/16/18.
//

#ifndef FLIGHTSIMULATOR_OPENSERVER_H
#define FLIGHTSIMULATOR_OPENSERVER_H

#include "Command.h"
#include <pthread.h>
#include "../Server/ServerRunner.h"
#include "../Server/ServerBuilder.h"
#include "../Threads/ThreadsVector.h"


class OpenServer: public Command {
private:
    Expression *port, *refreshRate;
public:
    OpenServer(Expression *a, Expression *b);
    ~OpenServer();
    void execute();
};


#endif //FLIGHTSIMULATOR_OPENSERVER_H
