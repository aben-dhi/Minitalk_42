/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-dhi <aben-dhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 19:29:07 by aben-dhi          #+#    #+#             */
/*   Updated: 2023/05/12 21:31:56 by aben-dhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

//Turn the string into binary
char	**str_to_bin(char *str)
{
	int		i;
	int		j;
	char	**bin;

	i = 0;
	bin = malloc (sizeof(char *) * (ft_strlen(str) + 1));
	while (str[i])
	{
		j = 7;
		bin[i] = malloc(sizeof(char) * 9);
		while (j >= 0)
		{
			bin[i][j] = (str[i] >> j) & 1;
			j--;
		}
		i++;
	}
	// bin[i] = "\n";
	bin[i] = NULL;
	return (bin);
}

//Send the signal to the server
void	send_signal(char **bin, int pid)
{
	int	i;
	int	j;

	i = 0;
	while (bin[i])
	{
		j = 0;
		while (j < 8)
		{
			if (bin[i][j] == 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			j++;
			usleep(200);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int		pid;
	char	**bin;

	if (argc != 3)
	{
		write(1, "Error Wrong Format\n", 20);
		return (0);
	}
	pid = ft_atoi(argv[1]);
	bin = str_to_bin(argv[2]);
	send_signal(bin, pid);
	return (0);
}
