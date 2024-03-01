#include <minitalk.h>

void handler(int sig)
{
    static int c = 0;
    static int bit = 0;

    if (sig == SIGUSR1)
        c |= (1 << (7 - bit));
    ++bit;
    if (bit > 7) {
        ft_printf("%c", c);
        if (c == '\0')
            ft_printf("\n");
        c = 0;
        bit = 0;
    }
}

int main(void)
{  
    ft_putstr_fd("Server PID: ", 1);
    ft_putnbr_fd(getpid(), 1);
    ft_putstr_fd("\n", 1);

    signal(SIGUSR1, handler);
    signal(SIGUSR2, handler);
    while (1)
    {
        pause();
    }
}
