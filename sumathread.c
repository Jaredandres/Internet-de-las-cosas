#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>
#define NUM_THREADS 10

int saldo;
sem_t protecSaldo; // este código es una mala practica del semaforo

void *suma(void *arg){
    sem_wait(&protecSaldo); // decrementa
    printf("El saldo inicial es %d\n", saldo);
    saldo = saldo + 100;
    printf("El saldo despues es %d\n", saldo);
    sem_post(&protecSaldo); // incrementa
    pthread_exit(NULL);
}

int main(){
    saldo = 0;
    pthread_t threadsInfo[NUM_THREADS];
    sem_init(&protecSaldo, 0, 1); // 1 valor inicial
    // Creat threads
    for (int i = 0; i < NUM_THREADS; i++){ 
        pthread_create(&threadsInfo[i], NULL, suma, NULL); 
    }
    // Wait for the threads
    for (int i = 0; i < NUM_THREADS; i++){
        pthread_join(threadsInfo[i], NULL);
    }
    printf("El final es %d\n", saldo);
    pthread_exit(NULL); // termina código
    printf("Nunca llega aqui");
}