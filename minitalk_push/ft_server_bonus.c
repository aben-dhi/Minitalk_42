/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-dhi <aben-dhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 19:35:41 by aben-dhi          #+#    #+#             */
/*   Updated: 2023/05/16 15:26:50 by aben-dhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	ft_handler1(int c, int pid)
{
	if (c == '\0')
	{
		write(1, "\n", 1);
		kill(pid, SIGUSR2);
	}
	else
		write(1, &c, 1);
}

void	ft_handler(int sig, siginfo_t *info, void *context)
{
	static int	i;
	static char	c;
	static int	pid;

	(void)context;
	if (pid != info->si_pid)
	{
		i = 0;
		pid = info->si_pid;
	}
	if (sig == SIGUSR1)
		c |= (1 << i++);
	else
		c |= (0 << i++);
	if (i == 8)
	{
		ft_handler1(c, info->si_pid);
		i = 0;
		c = 0;
	}
}

int	main(void)
{
	int					pid;
	char				*str;
	int					len;
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &ft_handler;
	pid = getpid();
	str = ft_itoa(pid);
	len = ft_strlen(str);
	ft_putstr_fd("PID: ", 1);
	write(1, str, len);
	write(1, "\n", 1);
	if (sigaction(SIGUSR1, &sa, NULL) == -1
		|| sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		write(1, "Error: signal handler registration failed\n", 43);
		return (1);
	}
	while (1)
		pause();
	return (0);
}
