//
// Created by shilo on 12/17/18.
//

#include "Plus.h"

double Plus::calculate() {
    return left->calculate() + right->calculate();
}