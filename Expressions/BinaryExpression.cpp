//
// Created by shilo on 12/17/18.
//

#include "BinaryExpression.h"


BinaryExpression::BinaryExpression(Expression *a, Expression *b)
{
    left = a;
    right = b;
}

BinaryExpression::~BinaryExpression() {
    delete left;
    delete right;
}