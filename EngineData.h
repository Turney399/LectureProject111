#include <pthread.h>
#include <unistd.h>


typedef struct {
    pthread_mutex_t engine_mutex;
    float voltage_position;
    float voltage_speed;
    int cruise;
    int speed_setp;
    int speed_actual;
    int position_setp;
    int position_actual;
    float accel_man;
    float break_man;
    float accel_command;
    float break_command;
    float feet_position;
    float mph_speed;
    float accel_volt;
    float break_volt;
} EngineData;