/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-dhi <aben-dhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 19:33:04 by aben-dhi          #+#    #+#             */
/*   Updated: 2023/05/14 19:36:26 by aben-dhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

void	ft_putstr_fd(char *s, int fd);
int		ft_strlen(char *s);
int		ft_atoi(char *str);
char	*ft_itoa(int n);
char	**str_to_bin(char *str);
void	send_signal(char **bin, int pid);
void	ft_handler(int sig, siginfo_t *info, void *context);

#endif