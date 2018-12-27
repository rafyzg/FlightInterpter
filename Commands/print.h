//
// Created by shilo on 12/16/18.
//

#ifndef FLIGHT_SIMULATOR_PRINT_H
#define FLIGHT_SIMULATOR_PRINT_H

#include "Command.h"
#include "vector"

class Print : public Command {
    Expression *a = nullptr;
    std::vector<std::string> toPrint;
public:
    explicit Print(std::vector<std::string> v);
    explicit Print(Expression *_a);
    void execute();

    ~Print();
};


#endif //FLIGHT_SIMULATOR_PRINT_H
