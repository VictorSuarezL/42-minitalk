/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanz-su <vsanz-su@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 19:58:33 by vsanz-su          #+#    #+#             */
/*   Updated: 2024/03/18 09:26:19 by vsanz-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minitalk.h>

void	sig_send_msg(pid_t pid, char *s)
{
	int	i;
	int	j;

	i = 0;
	while (s[i])
	{
		j = 7;
		while (j >= 0)
		{
			if ((s[i] >> j) & 1)
			{
				kill(pid, SIGUSR1);
			}
			else
			{
				kill(pid, SIGUSR2);
			}
			usleep(100);
			j--;
		}
		i++;
	}
}

int	main(int ac, char *av[])
{
	int	pid;

	if (ac < 2)
		return (0);
	pid = ft_atoi(av[1]);
	if (pid <= 0)
		return (0);
	sig_send_msg(pid, av[2]);
	sig_send_msg(pid, "\n");
}
