#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "EngineData.h"

void cruise_controller(int argc, char* argv[])
{

    int shm_fd = shm_open("/myshm", O_CREAT | O_RDWR, 0666);
    if (shm_fd == -1)
    {
        perror("shm_open");
        return 1;
    }
    //set size of shared memory
    if (ftruncate(shm_fd, sizeof(EngineData) == -1))
    {
        perror("ftruncate");
        return 1;
    }
    //data* mydata=malloc(sizeof(data)+layers*sizeof(double));
    EngineData* data=mmap(0, sizeof(EngineData),PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
    if (data == MAP_FAILED)
    {
        perror("mmap");
        return 1;
    }


    

    return;
}