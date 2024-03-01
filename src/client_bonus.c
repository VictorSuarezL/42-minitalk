#include <minitalk.h>

void sig_send_msg(pid_t pid, char *s)
{
    int i;
    int j;

    i = 0;
    while (s[i])
    {
        j = 7;
        while (j >= 0)
        {
            if ((s[i]>>j) & 1){
                kill(pid, SIGUSR1);
            }
            else{
                kill(pid, SIGUSR2);
            }
            usleep(100);
            j--;
        }
        i++;
    }
}

void handler_checker(int sig)
{
    static int flag;

    flag += 0;
    if (flag == 0)
    {
        ft_printf("MSG in SRVR: ");
        flag += 1;
    }
    
    if (sig == SIGUSR1)
        ft_printf("1");
    else if (sig == SIGUSR2)
        ft_printf("0");
}

int main(int ac, char *av[])
{
    int pid;

    signal(SIGUSR1, handler_checker);
    signal(SIGUSR2, handler_checker);

    pid = ft_atoi(av[1]);
    sig_send_msg(pid, av[2]);
    sig_send_msg(pid, "\n");
    // sleep(1);
    // kill(pid, SIGKILL);
}