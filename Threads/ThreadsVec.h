#ifndef FLIGHT_SIMULATOR_THREADSVECTOR_H
#define FLIGHT_SIMULATOR_THREADSVECTOR_H

#include <vector>
#include <pthread.h>

extern std::vector<pthread_t*> threadsVec;
extern bool shouldStopThreads;

class ThreadsVector {

};


#endif //FLIGHT_SIMULATOR_THREADSVECTOR_H
