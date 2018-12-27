//
// Created by shilo on 12/17/18.
//

#ifndef FLIGHTSIMULATOR_EXPRESSION_H
#define FLIGHTSIMULATOR_EXPRESSION_H


class Expression {

public:
    virtual double calculate() = 0;

    virtual ~Expression() = default;
};


#endif //FLIGHTSIMULATOR_EXPRESSION_H
