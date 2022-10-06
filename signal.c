#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int cond;

void hola(int signalNumb){
    printf("Recibi la senal %d", signalNumb);
    
}
void terminalWhile(int sigNumber){
    printf("Terminando while\n");
    cond = 0;

}


int main(){
    signal(12,terminalWhile);
    signal(2,hola);
    cond = 1;
    while(cond == 1){
        printf("Trabajando\n");
        sleep(1);
    }
    printf("Aqui nunca llega\n");
    return 0;
}