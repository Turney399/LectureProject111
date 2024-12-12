#include <pthread.h>
#include <unistd.h>


typedef struct {
    pthread_mutex_t engine_mutex;

} EngineData;