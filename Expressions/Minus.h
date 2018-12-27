//
// Created by shilo on 12/17/18.
//

#ifndef FLIGHTSIMULATOR_MINUS_H
#define FLIGHTSIMULATOR_MINUS_H

#include "BinaryExpression.h"

class Minus : public BinaryExpression {
    using BinaryExpression:: BinaryExpression;
public:
    double calculate();
};


#endif //FLIGHTSIMULATOR_MINUS_H
