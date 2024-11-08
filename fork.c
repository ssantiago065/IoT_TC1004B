#include <stdio.h>
#include <unistd.h>

int main(){
    int a = 0;
    
    int pid = fork();
    if(pid==0){
        printf("Soy el proceso hijo\n");
        execl("./hello","hello","Sergio","yo",(char *) NULL);
        printf("ESTO NO DEBERIA IMPRIMIRSE");
        return 0;
    }
    printf("Soy el proceso padre\n");
    sleep(20);
    return 0;
}