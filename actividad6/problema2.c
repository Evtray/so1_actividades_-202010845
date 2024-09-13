#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();  // Crear proceso hijo
    
    if (pid < 0) {
        perror("Error en fork");
        exit(1);
    }
    
    if (pid == 0) {
        printf("proceso hijo, mi PID es %d\n", getpid());
        exit(0);  
    } else {
     
        printf(" proceso padre, mi PID es %d\n", getpid());
        printf("Proceso hijo terminado-creando zombie\n");
        
        sleep(60);
        
        wait(NULL);
        printf("Proceso recogido. Ya no es un zombie.\n");
    }

    return 0;
}