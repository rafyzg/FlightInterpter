//
// Created by shilo on 12/16/18.
//

#include "connect.h"

Connect::Connect(std::string _ip, Expression *_port) {
    ip = _ip;
    port = _port;
}

Connect::~Connect() {
    delete port;
}

/*
 * Expected arguments:
 * 0 = IP
 * 1 = port
 */
void Connect::execute() {
    ClientBuilder builder;
    builder.set_client(ip, port->calculate());
}


