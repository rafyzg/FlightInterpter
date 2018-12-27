//
// Created by shilo on 12/17/18.
//

#include "UnaryMinus.h"

UnaryMinus::UnaryMinus(Expression *_exp) {
   exp = _exp;
}

double UnaryMinus::calculate() {
    return  -1 * exp->calculate();
}

UnaryMinus::~UnaryMinus() {
    delete exp;
}