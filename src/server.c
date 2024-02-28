#include <minitalk.h>

void handler(int sig)
{
    // printf("--> in sig_handler\n");
    // if (sig == SIGUSR1)
    // {
    //     printf("received: 1\n");
    // }
    // else
    // {
    //     printf("received: 0\n");
    // }
    static char c = 0;
    static int bit = 0;
    // static pid_t client_pid = 0;

    // if (client_pid != 0)
    // {
    //     client_pid = info->si_pid;
    // }
    

    if (sig == SIGUSR1)
        c |= (1 << (7 - bit));
    ++bit;
    if (bit > 7) {
        write(1, &c, 1);
        c = 0;
        bit = 0;
    }
}

int main(void)
{  
    // struct sigaction sa;
    ft_putstr_fd("Server PID: ", 1);
    ft_putnbr_fd(getpid(), 1);
    ft_putstr_fd("\n", 1);

    signal(SIGUSR1, handler);
    signal(SIGUSR2, handler);
    // sa.action = handler;
    while (1)
    {
        pause();
    }
}

/* #include <stdio.h>
#include <signal.h>
#include <sys/types.h>
 
//Declaramos los prototipos de funciones
//Funcion manejador
void manejador (int signum){
 //Si la señal es SIGUSR1 entonces
 if(signum==SIGUSR1){
 printf("Recibi una senal de mi padre %d\n",signum);
 }
 //Si es SIGUSR2 entonces
 else
 {
 printf("Recibi una senal de mi hijo %d\n",signum);
 }
 bandera=0;
}
 
//Variable global
int bandera = 1;
 
//Función principal
int main(int argc, char **argv)
{
 //Declaramos variables
 int status,pid;
 
 //Si fork() es igual a 0 entonces es hijo
 if((pid=fork())==0)
 {
 //Proceso hijo
 printf("Soy hijo y estoy esperando una señal de mi padre, mi pid es: %d\n",getpid());
 //Capturamos la señal SIGUSR1
 signal(SIGUSR1,manejador);
 //Utilizamos la variable bandera para que el proceso no termine
 while(bandera);
 //Usamos el comando kill para enviar una señal
 //Se necesita el pid del padre y la señal
 kill(getppid(),SIGUSR2);
 }
 else
 {
 //Proceso padre
 //Capturamos la señal SIGUSR2
 signal(SIGUSR2,manejador);
 printf("Soy Padre, mi pid es: %d\n",getpid());
 //Esperamos 3 segundos
 sleep(3);
 //Usamos el comando kill para enviar una señal
 //Se necesita el pid y la señal
 kill(pid, SIGUSR1);
 //Esperamos que termine el hijo
 wait(&status);
 printf("Mi hijo termino con un estado: %d\n",status);
 }
} */
 
