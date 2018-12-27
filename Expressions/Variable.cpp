//
// Created by shilo on 12/17/18.
//

#include "Variable.h"
#include <iostream>

Variable::Variable(std::string _name) {
    name = _name;
}

double Variable:: calculate()
{
    if (symbolExists(name)) {
        return symbolMap.at(name)->getValue();
    }
    else {
        throw "Variable doesn't exist";
    }

}