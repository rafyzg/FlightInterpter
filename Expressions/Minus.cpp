//
// Created by shilo on 12/17/18.
//

#include "Minus.h"


double Minus::calculate() {
    return left->calculate() - right->calculate();
}