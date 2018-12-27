#include "Symbol.h"

Symbol::Symbol() {
    // Empty symbol
}

Symbol::Symbol(double value) {
    Symbol::value = value;
}

Symbol::Symbol(std::string address) {
    setPath(address);
}

double Symbol::getValue() const {
    return value;
}

void Symbol::setValue(double value, bool notifyServer)
{
    // Set local value
    Symbol::value = value;
    // If bound, send value to simulator
    if (pathSet() && notifyServer) {
        std::string valueStr = std::to_string(value);
        ClientBuilder builder;
        Client* client = builder.get_client();
        client->send_message("set " + path + ' ' + valueStr + "\r\n");
    }
}

const std::string &Symbol::getPath() const {
    return path;
}

void Symbol::setPath(const std::string &address)
{
    Symbol::path = address;
}

bool Symbol::pathSet() {
    return !(path == "");
}
