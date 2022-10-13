#include <pthread.h>
#include <stdio.h>

typedef struct threa_Data{
    int threadId;
    char name[20];
    //..
} ThreaData;

void *holaMundo(void *arg){
    ThreaData *myData = (ThreaData *)arg;
    printf("Hola desde el hilo %d\n", myData -> threadId);
    pthread_exit(NULL);

}

int main(){
    for(int i = 0; i < 100; ++i){
    ThreaData myData;
    pthread_t threadId;
    myData.threadId = i;
    pthread_create(&threadId,NULL,holaMundo,(void *)&myData);
    }
    pthread_exit(NULL);
    printf("Nunca llega");
    
}