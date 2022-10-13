#include <ctype.h>
#include <unistd.h>
#include <stdio.h>



int main(){
    char c;
    char may;
    int n;
    char vocales[] = {'A', 'E', 'I', 'O', 'U'};
    do{
        n = read(STDIN_FILENO,&c,1);
        may = toupper(c);
        for(char vocal : vocales) {
            if (vocal == may) {
                write(STDOUT_FILENO,'1',1);
                continue;
            }
        }
        write(STDOUT_FILENO,&may,1);
        
    }while(n != 0);
    return 0;
}