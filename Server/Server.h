#ifndef FLIGHTSIMULATOR_SERVER_H
#define FLIGHTSIMULATOR_SERVER_H

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>



class Server {
private:
    int sock;
    std::string address;
    int port;
    struct sockaddr_in server;
    char buffer[1024] = {0};
    int read_value;
public:
    Server();
    bool bind_to(int port);
    int listen_to();
    void read_from(int new_socket);
    char* get_buffer();
    int get_read_value();
    void stop();
};


#endif //FLIGHTSIMULATOR_SERVER_H
