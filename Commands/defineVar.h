//
// Created by shilo on 12/16/18.
//

#ifndef FLIGHTSIMULATOR_DEFINEVAR_H
#define FLIGHTSIMULATOR_DEFINEVAR_H

#include "Command.h"
#include "../Interpreter/SymbolMap.h"

class DefineVar: public Command {

    Expression *exp = nullptr;
    std::string address = "";
    std::string name = "";
    std::string var = "";

public:
    // Constructors
    DefineVar(std::string _name, std::string _address);
    DefineVar(std::string _name, Expression * _exp);
    DefineVar(std::string _name, std::string _var, bool bindVar);
    void execute();

    ~DefineVar();
};


#endif//FLIGHTSIMULATOR_DEFINEVAR_H
