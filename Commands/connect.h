//
// Created by shilo on 12/16/18.
//

#ifndef FLIGHTSIMULATOR_CONNECT_H
#define FLIGHTSIMULATOR_CONNECT_H

#include "Command.h"
#include "../Interpreter/SymbolMap.h"
#include "my_client_builder.h"


class Connect: public Command {
std::string ip;
Expression *port;

public:
    Connect(std::string _ip, Expression *_port);
    void execute();
    ~Connect();
};


#endif //FLIGHTSIMULATOR_CONNECT_H
