//
// Created by shilo on 12/17/18.
//

#ifndef FLIGHTSIMULATOR_PLUS_H
#define FLIGHTSIMULATOR_PLUS_H

#include "BinaryExpression.h"
class Plus : public BinaryExpression{
    using BinaryExpression:: BinaryExpression;
public:
    double calculate();
};


#endif //FLIGHTSIMULATOR_PLUS_H
