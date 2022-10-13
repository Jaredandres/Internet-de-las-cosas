#include <stdio.h>
#include <unistd.h>

int main(){
    FILE *lsOutput;
    FILE *tomayIntput;
    int linea = 0;
    char readBuffer[80];
    lsOutput = popen("ls *.c","r");
    tomayIntput = popen("./tomay","w");
   

    while(fgets(readBuffer,80 , lsOutput)){ 
        for(int i = 0; i < 80; ++i ){
            if(readBuffer[i] == '\0'){
                break;
            }
            if(readBuffer[i] == '\n'){
                ++linea;
            }
        }
        fputs(readBuffer,tomayIntput);
        
        }
    pclose(lsOutput);
    pclose(tomayIntput);
printf("%d linea\n", linea);
}