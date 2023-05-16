/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-dhi <aben-dhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 19:35:57 by aben-dhi          #+#    #+#             */
/*   Updated: 2023/05/16 16:04:37 by aben-dhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>

void			ft_putstr_fd(char *s, int fd);
int				ft_strlen(char *s);
int				ft_atoi(char *str);
char			*ft_itoa(int n);
unsigned char	**str_to_bin(char *str);
void			send_signal(unsigned char **bin, int pid);
void			ft_handler(int sig, siginfo_t *info, void *context);

#endif