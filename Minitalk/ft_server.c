/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-dhi <aben-dhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 19:29:15 by aben-dhi          #+#    #+#             */
/*   Updated: 2023/05/12 16:39:57 by aben-dhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_handler(int sig, siginfo_t *info, void *context)
{
	static int	i;
	static char	c;

	(void)info;
	(void)context;
	if (sig == SIGUSR1)
	{
		c |= (1 << i);
		i++;
	}
	else if (sig == SIGUSR2)
	{
		c |= (0 << i);
		i++;
	}
	if (i == 8)
	{
		if (c == '\0')
		{
			write(1, "\n", 1);
			exit(0);
		}
		write(1, &c, 1);
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
	sigemptyset(&sa.sa_mask);
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
