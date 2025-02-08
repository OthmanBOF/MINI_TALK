/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouftou <obouftou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 18:13:49 by obouftou          #+#    #+#             */
/*   Updated: 2025/02/08 15:09:44 by obouftou         ###   ########.fr       */
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
void	seen(int sig)
{
	if (sig == SIGUSR1)
		ft_putstr_fd(GRN "Message Acknowledged. \n" "\e[0m", 1);
}
int main(int ac, char **av)
{
	int pid;
	int x;

	x = 0;
	if (ac == 3 && av[2][0] != '\0')
	{
		pid = pid_check(av[1]);
		if (pid)
		{
			ft_putstr_fd(GRN "Valid PID.\n" "e[0m", 1);
			signal(SIGUSR1, seen);	
		} 
	}
}