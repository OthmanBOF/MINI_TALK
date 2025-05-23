/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouftou <obouftou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 22:27:20 by obouftou          #+#    #+#             */
/*   Updated: 2025/02/12 14:47:58 by obouftou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	pid_check(char *pid_str)
{
	int	i;
	int	pid;

	i = 0;
	while (pid_str[i])
	{
		if (pid_str[i] < '0' || pid_str[i] > '9')
		{
			ft_putstr_fd(RED "PID has non-digit chars.\n" "\e[0m", 2);
			return (0);
		}
		i++;
	}
	pid = ft_atoi(pid_str);
	if (pid <= 0)
	{
		ft_putstr_fd(RED "PID must be positive.\n" "\e[0m", 2);
		return (0);
	}
	return (pid);
}

void	sig_send(int pid, char x)
{
	int	sig;
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if (x & (1 << bit))
			sig = SIGUSR1;
		else
			sig = SIGUSR2;
		if (kill(pid, sig) == -1)
		{
			ft_putstr_fd(RED "Invalid PID. Signal failed.\n" "\e[0m", 2);
			exit(1);
		}
		usleep(90);
		usleep(110);
		bit++;
	}
}

int	main(int ac, char **av)
{
	int	pid;
	int	x;

	x = 0;
	if (ac == 3 && av[2][0] != '\0')
	{
		pid = pid_check(av[1]);
		if (pid != 0)
		{
			ft_putstr_fd(GRN "Valid PID. Sending ...\n" "\e[0m", 1);
			while (av[2][x])
				sig_send(pid, av[2][x++]);
			sig_send(pid, '\0');
		}
	}
	else
	{
		ft_putstr_fd(RED "Invalid args or empty msg.\n" "\e[0m", 2);
		ft_putstr_fd(PUR "Usage: ./client [PID] [MSG]\n" "\e[0m", 2);
	}
	return (0);
}
