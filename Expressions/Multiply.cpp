//
// Created by shilo on 12/17/18.
//

#include "Multiply.h"

double Multiply::calculate() {
    return left->calculate() * right->calculate();
}