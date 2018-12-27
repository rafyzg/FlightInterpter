//
// Created by shilo on 12/16/18.
//

#include "sleep.h"
#include <unistd.h>
#include <thread>

Sleep::Sleep(Expression *_a) {
    a = _a;
}

void Sleep::execute() {
    // Sleep amount specified
    std::this_thread::sleep_for(std::chrono::milliseconds((int) a->calculate()));
}

Sleep::~Sleep() {
    delete a;
}