#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void* thread_function(void* arg) {
    printf("Hilo creado en el proceso hijo\n");
    return NULL;
}

int main() {
    pid_t pid;

    pid = fork();
    if (pid == 0) { 
        printf("Proceso hijo creado (PID: %d)\n", getpid());
        
        pid = fork();
        if (pid == 0) {
            printf("Proceso nieto creado (PID: %d)\n", getpid());
        } else {
            pthread_t thread;
            pthread_create(&thread, NULL, thread_function, NULL);
            pthread_join(thread, NULL); 
        }
    }

    fork();

    sleep(2);
    return 0;
}
