/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-dhi <aben-dhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 19:35:28 by aben-dhi          #+#    #+#             */
/*   Updated: 2023/05/16 15:09:55 by aben-dhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	sent_handler(int sig)
{
	if (sig == SIGUSR2)
	{
		usleep(100);
		write(1, "Message Sent\n", 13);
		exit(0);
	}
}

//Turn the string into binary
unsigned char	**str_to_bin(char *str)
{
	int				i;
	int				j;
	unsigned char	**bin;

	i = 0;
	bin = malloc (sizeof(unsigned char *) * (ft_strlen(str) + 1));
	while (str[i])
	{
		j = 7;
		bin[i] = malloc(sizeof(unsigned char) * 8);
		while (j >= 0)
		{
			bin[i][j] = (str[i] >> j) & 1;
			j--;
		}
		i++;
	}
	bin[i] = NULL;
	return (bin);
}

//Send the signal to the server
void	send_signal(unsigned char **bin, int pid)
{
	int					i;
	int					j;

	i = -1;
	while (bin[++i])
	{
		j = -1;
		while (++j < 8)
		{
			if (bin[i][j] == 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(100);
		}
	}
	if (bin[i] == NULL)
	{
		j = -1;
		while (++j < 8)
		{
			kill(pid, SIGUSR2);
			usleep(100);
		}
	}
}

int	main(int argc, char **argv)
{
	int					pid;
	unsigned char		**bin;

	if (argc != 3)
	{
		write(1, "Error Wrong Format\n", 20);
		return (0);
	}
	pid = ft_atoi(argv[1]);
	bin = str_to_bin(argv[2]);
	if (kill(pid, 0) == -1)
	{
		write(1, "Invalid server PID. Exiting...\n", 31);
		return (0);
	}
	signal(SIGUSR2, sent_handler);
	send_signal(bin, pid);
	while (1)
		sleep (1);
	return (0);
}
