#include <pthread.h>
#include <stdio.h>
#define NUM_THREADS 100

typedef struct thread_Data{
    int threadId;
    char name[20];
    //..
} ThreaData;
typedef char caracter;

void *holaMundo(void *arg){
    ThreaData *myData = (ThreaData *)arg;
    printf("Hola desde el hilo %d\n", myData -> threadId);
    pthread_exit(NULL);

}

int main(){
    ThreaData thread_Data[NUM_THREADS];
    for(int i = 0; i < NUM_THREADS; ++i){
    pthread_t threadId;
    thread_Data[i].threadId = i;
    pthread_create(&threadId,NULL,holaMundo,(void *)&threa_Data[i]);
    }
    pthread_exit(NULL);
    printf("Nunca llega");
    
}