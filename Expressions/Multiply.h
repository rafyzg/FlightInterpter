//
// Created by shilo on 12/17/18.
//

#ifndef FLIGHT_SIMULATOR_MULTIPLY_H
#define FLIGHT_SIMULATOR_MULTIPLY_H


#include "BinaryExpression.h"

class Multiply : public BinaryExpression {
    using BinaryExpression::BinaryExpression;
public:
    double calculate();
};


#endif //FLIGHT_SIMULATOR_MULTIPLY_H
