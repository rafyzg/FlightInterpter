#include "ServerRunner.h"

/*
    - Constructor form ServerRunner
*/

ServerRunner::ServerRunner(int port, int refresh_rate) {

    ServerBuilder builder;
    builder.set_server(port);
    this->server = builder.get_server();

    this->port = port;
    this->refresh = refresh_rate;
    initializeValues();
}

/*
    - Destructor for ServerRunner
*/
ServerRunner::~ServerRunner() {
    delete server;
}

/*
    - Function for seting up the values
*/
void ServerRunner::initializeValues ()
{
    valueMap.emplace(std::make_pair("/instrumentation/airspeed-indicator/indicated-speed-kt", 0));
    valueMap.emplace(std::make_pair("/instrumentation/altimeter/indicated-altitude-ft", 0));
    valueMap.emplace(std::make_pair("/instrumentation/altimeter/pressure-alt-ft", 0));
    valueMap.emplace(std::make_pair("/instrumentation/attitude-indicator/indicated-pitch-deg", 0));
    valueMap.emplace(std::make_pair("/instrumentation/attitude-indicator/indicated-roll-deg", 0));
    valueMap.emplace(std::make_pair("/instrumentation/attitude-indicator/internal-pitch-deg", 0));
    valueMap.emplace(std::make_pair("/instrumentation/attitude-indicator/internal-roll-deg", 0));
    valueMap.emplace(std::make_pair("/instrumentation/encoder/indicated-altitude-ft", 0));
    valueMap.emplace(std::make_pair("/instrumentation/encoder/pressure-alt-ft", 0));
    valueMap.emplace(std::make_pair("/instrumentation/gps/indicated-altitude-ft", 0));
    valueMap.emplace(std::make_pair("/instrumentation/gps/indicated-ground-speed-kt", 0));
    valueMap.emplace(std::make_pair("/instrumentation/gps/indicated-vertical-speed", 0));
    valueMap.emplace(std::make_pair("/instrumentation/heading-indicator/indicated-heading-deg", 0));
    valueMap.emplace(std::make_pair("/instrumentation/magnetic-compass/indicated-heading-deg", 0));
    valueMap.emplace(std::make_pair("/instrumentation/slip-skid-ball/indicated-slip-skid", 0));
    valueMap.emplace(std::make_pair("/instrumentation/turn-indicator/indicated-turn-rate", 0));
    valueMap.emplace(std::make_pair("/instrumentation/vertical-speed-indicator/indicated-speed-fpm", 0));
    valueMap.emplace(std::make_pair("/controls/flight/aileron", 0));
    valueMap.emplace(std::make_pair("/controls/flight/elevator", 0));
    valueMap.emplace(std::make_pair("/controls/flight/rudder", 0));
    valueMap.emplace(std::make_pair("/controls/flight/flaps", 0));
    valueMap.emplace(std::make_pair("/controls/engines/engine/throttle", 0));
    valueMap.emplace(std::make_pair("/engines/engine/rpm", 0));
}

/*
    - Function listing to new socket
*/
int ServerRunner::listen() {
    int new_socket = server->listen_to();
    return new_socket;
}

void ServerRunner::run(int new_socket)
{

    std::stringstream stream; //Data from server
    CodeRow input(',', false);

    auto interval = std::chrono::nanoseconds(std::chrono::seconds(1)) / refresh;
    while (!shouldStopThreads) {
        // Get current time
        auto start = std::chrono::system_clock::now();

        // Get most recent line from server
        server->read_from(new_socket);
        stream << server->get_buffer();
        stream >> input;
        for (int i = 0; i < input.size(); i++) { //Setting the values to map
            valueMap[valueNames[i]] = stof(input[i]);
        }

        // Mutex and lock
        MutexSingle mutexSingle;
        mutexSingle.lock();

        for (std::pair<std::string, Symbol*> symbol : symbolMap) {
            string path = symbol.second->getPath();
            if (valueMap.count(path) > 0) {
                symbol.second->setValue(valueMap[symbol.second->getPath()], false);
            }
        }

        mutexSingle.unlock(); //unlocking mutex

        //Setting the thread
        auto end = std::chrono::system_clock::now();
        auto delay = end - start;
        auto sleep_duration = interval - delay;
        std::this_thread::sleep_for(sleep_duration);
    }
}

/*
    - Function for stopping the server
*/
void ServerRunner::stop() {
    server->stop();
}
