#include <stdio.h>
#include <signal.h>



void no_me_matas(int signum){
    printf("Recibi la señal %d\n", signum);
    printf("No me puedes matar");
}

int condicion;
void termina_ciclo(int signum){
    printf("Rompiendo ciclo");
    condicion = 0;
}

int main(){
    signal(2, no_me_matas);
    signal(10, termina_ciclo);
    condicion = 1;
    while(condicion){
        printf("trabajando\n");
        sleep(2);
    }
    printf("terminado");
    return 0;
}