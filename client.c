/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouftou <obouftou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 22:27:20 by obouftou          #+#    #+#             */
/*   Updated: 2025/02/06 14:54:18 by obouftou         ###   ########.fr       */
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
		if (!ft_isdigit(pid_str[i]))
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


int	main (int ac ,char **av)
{
	int pid;
	int x;

	x = 0;
	if (ac == 3 && av[2][0] != '\0')
	{
		pid = pid_check(av[1]);
		if (pid != 0)
		{
			ft_putstr_fd(GRN);
		}
	}
}