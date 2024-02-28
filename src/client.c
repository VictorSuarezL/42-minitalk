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
    sleep(1);
    kill(pid, SIGKILL);
}

int main(int ac, char *av[])
{
    int pid;

    pid = ft_atoi(av[1]);
    sig_send_msg(pid, av[2]);
}