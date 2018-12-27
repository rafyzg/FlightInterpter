//Condition
// Created by shilo on 12/16/18.
//

#ifndef FLIGHTSIMULATOR_IF_H
#define FLIGHTSIMULATOR_IF_H


#include "condition.h"

class If: public Condition {
    // Inherit constructor and destructor from Condition
    using Condition::Condition;
public:
    void execute();
};


#endif //FLIGHTSIMULATOR_IF_H
