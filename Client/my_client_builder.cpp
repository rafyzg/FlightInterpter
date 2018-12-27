//
// Created by shilo on 12/21/18.
//

#include "my_client_builder.h"


void ClientBuilder::set_client(string ip, int port)
{
    if (!client_set) {
        client = new Client;
        client->connect_to(ip, port);
        client_set = true;
    }
}


Client* ClientBuilder::get_client() {
    if (client_set) {
        return client;
    }
    throw "Client is not set";

}

void ClientBuilder::stop() {
    if (client_set) {
        client->stop();
        delete client;
    }
}