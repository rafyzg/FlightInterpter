#include <unistd.h>
#include "Server.h"

#define PORT 5400
/*
 * Constructor for Server
 */
Server::Server() {
    sock = -1;
    port = 0;
}

/*
 * Function for Binding the server
 */
bool Server::bind_to(int port)
{
    this->port = port;
    //Create socket if didn't
    if (sock == -1) {
        sock = socket(AF_INET , SOCK_STREAM , 0);
        if (sock == -1) {
            perror("Error for creating socket");
            return false;
        }
    }

    //Setting the socket to 8080
    int opt = 1;
    if (setsockopt(sock, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        return false;
    }

    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_family = AF_INET;
    server.sin_port = htons(port);

    if ((bind(sock, (struct sockaddr *)&server, sizeof(address))) < 0) { //Failed at binding
        perror("Failed to bind server");
        return false;
    }
    return true;
}

/*
 * Function for Listening for the server
 */
int Server::listen_to()
{

    if (listen(sock, 3) < 0) {
        //Didn't get to listen
        perror("listen");
        return false;
    }

    int addrlen = sizeof(address);
    int new_socket;
    if ((new_socket = accept(sock, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) { //Trying to connecto to new client
        perror("accept");
        return false;
    }
    return new_socket; //Returning socket
}

/*
 * Function for Reading from the server
 */
void Server::read_from(int new_socket) {
    memset(buffer, 0, sizeof(buffer));
    read_value = read(new_socket, buffer, 1024);
}

char* Server::get_buffer() {
    return buffer;
}

int Server::get_read_value() {
    return read_value;
}

//Function for closing the connection
void Server::stop() {
    shutdown(sock, SHUT_WR);
    close(sock);
}