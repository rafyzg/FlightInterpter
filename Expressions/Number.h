//
// Created by shilo on 12/17/18.
//

#ifndef FLIGHTSIMULATOR_NUMBER_H
#define FLIGHTSIMULATOR_NUMBER_H

#include "Expression.h"
#include <string>

class Number : public Expression {
private:
    double num;
public:
    Number(double d);
    Number(int i);
    Number(std::string s);
    double calculate();
};


#endif //FLIGHTSIMULATOR_NUMBER_H
