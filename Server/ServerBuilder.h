#ifndef FLIGHT_SIMULATOR_GET_SERVER_H
#define FLIGHT_SIMULATOR_GET_SERVER_H

#include "Server.h"

static Server* server;
static bool server_set = false;

class ServerBuilder {
public:
    void set_server(int port); //Setup server
    Server* get_server(); //Returns server
    void stop(); //Stops the server
};


#endif //FLIGHT_SIMULATOR_GET_SERVER_H
