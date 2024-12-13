/*
 * File name: controller.c
 * Description: controller for cruise controller
 * Names: Rose Zickefoose, Abe Kesting, Chance Mason, Vincent Vassallo
 * Date: 12/12/24
 */

#include "controller.h"
#include "EngineData.h"

#define ON 1
#define OFF 0

void controller(void* data) {
    EngineData* local_data = (EngineData *) data;
    // If cruise is on then control
    if(local_data->cruise == ON) {
        // If you are too close to the car in front of you you need to break and not accelerate
        if(local_data->position_actual < local_data->position_setp){
            // Break command cannot be above 100%
            if(local_data->break_command + 1 <= 100) {
                (local_data->break_command)++;
            } else {
                local_data->break_command = 100;
            }
            (local_data->accel_command) = 0;
        } 
        // If the car in front of you is further than wanted, then accelerate if speed_setp is greater than speed_actual and not break
        else if(local_data->position_actual > local_data->position_setp) {
            // If the set speed is greater than the actual speed, then accelerate
            if(local_data->speed_setp > local_data->speed_actual) {
                // Acceleration cannot be above 100%
                if(local_data->accel_command + 1 <= 100) {
                    (local_data->accel_command)++;
                } else {
                    local_data->accel_command = 100;
                }
            } 
            // If the current speed is greater than desired, then don't accelerate (doesn't need break since friction will do it for us)
            else if(local_data->speed_setp < local_data->speed_actual) {
                (local_data->accel_command) = 0;
            }

            (local_data->break_command) = 0;
        } 
        // If everything is what is desired then don't break and don't accelerate
        else {
            (local_data->accel_command) = 0;
            (local_data->break_command) = 0;
        }
    } 
    // If cruise is NOT on then the driver has to drive themselves :O
    else {
        local_data->accel_command = local_data->accel_man;
        local_data->break_command = local_data->break_man;
    }
}