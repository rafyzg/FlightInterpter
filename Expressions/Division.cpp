//
// Created by shilo on 12/17/18.
//

#include "Division.h"


double Division::calculate() {
    return left->calculate() / right->calculate();
}