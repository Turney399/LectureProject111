#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX 1024
char line[MAX];

void *input_from_client(void *arg) {
    // Clear the buffer
    bzero(line, MAX);
    // Read input from the server's standard input
    fgets(line, MAX, stdin);
    // Remove the newline character from the input
    line[strlen(line) - 1] = 0;
    strcmp()
}
void *displayt_to_client(void *arg) {
    // Clear the buffer
    bzero(line, MAX);
    // Read input from the server's standard input
    fgets(line, MAX, stdin);
    // Remove the newline character from the input
    line[strlen(line) - 1] = 0;
    strcmp()
}

int user_interface(int speed_setp, int position_setp) {
    printf("Initializing\n");
    printf("Is cruise on or off?: ");
    // Read input from the server's standard input
    fgets(line, MAX, stdin);
    // Remove the newline character from the input
    line[strlen(line) - 1] = 0;
    while (1) {
        if(cruise == 1) {
            printf("%d", speed_setp);
        } else {

        }
        // Create threads for reading from and writing to the client
        pthread_t input_thread, output_thread;
        pthread_create(&input_thread, NULL, input_from_client, NULL);
        pthread_create(&ouput_thread, NULL, display_to_client, NULL);

        // Wait for the threads to finish
        pthread_join(read_thread, NULL);
        pthread_join(write_thread, NULL);
    }
    return 0;
}