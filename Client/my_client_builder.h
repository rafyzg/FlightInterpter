//
// Created by shilo on 12/20/18.
//

#ifndef FLIGHT_SIMULATOR_GET_CLIENT_H
#define FLIGHT_SIMULATOR_GET_CLIENT_H


#include "my_client.h"

static Client* client;
static bool client_set = false;

class ClientBuilder {
public:
    void set_client(string ip, int port);
    Client* get_client();
    void stop();
};


#endif //FLIGHT_SIMULATOR_GET_CLIENT_H
