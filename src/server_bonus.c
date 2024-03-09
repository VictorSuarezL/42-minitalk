/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanz-su <vsanz-su@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 19:59:02 by vsanz-su          #+#    #+#             */
/*   Updated: 2024/03/09 19:59:25 by vsanz-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minitalk.h>

void	handler(int sig, siginfo_t *info, void *other)
{
	static char	c;
	static int	bit;

	c = 0;
	bit = 0;
	(void)other;
	if (sig == SIGUSR1)
		c |= (1 << (7 - bit));
	++bit;
	if (bit > 7)
	{
		ft_printf("%c", c);
		c = 0;
		bit = 0;
	}
	if (sig == SIGUSR1)
		kill(info->si_pid, SIGUSR1);
	else if (sig == SIGUSR2)
		kill(info->si_pid, SIGUSR2);
}

int	main(void)
{
	struct sigaction	sa;

	ft_putstr_fd("Server Bonus PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd("\n", 1);
	sa.sa_sigaction = handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, 0);
	sigaction(SIGUSR2, &sa, 0);
	while (1)
	{
		pause();
	}
}
