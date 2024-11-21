#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void *hola(void *arg) {
    int pid = *((int *) arg);
    printf("Hola desde el hilo: %d\n", pid);
    pthread_exit(NULL);
}

int saldo;

void *incrementarSaldo(void *arg) {
    saldo += 100;
    pthread_exit(NULL);
}

int main() {
    int num_threads = 20;
    pthread_t hiloStatus[num_threads];
    int pid[num_threads];

    for (int i = 0; i < num_threads; i++) {
        pid[i] = i;
        pthread_create(&hiloStatus[i], NULL, incrementarSaldo, ( void*)&pid[i]);
    }
    for (size_t i = 0; i < 20; i++)
    {
        pthread_join(hiloStatus[i], NULL);
    }
    
    printf("Saldo al final: %d\n", saldo);
    pthread_exit(NULL);
}
