/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouftou <obouftou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 22:27:30 by obouftou          #+#    #+#             */
/*   Updated: 2025/02/07 13:09:49 by obouftou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"


void    bit_to_arr(int sin, siginfo_t *info, void *context)
{
	static int	pid;
	static int	p_bit;
	static char	c;

	if (pid != info->si_pid)
	{
		pid = info->si_pid;
		p_bit = 0;
		c = 0;
	}
	if (sin == SIGUSR1)
		c |= (1 << p_bit);
	p_bit++;
	if (p_bit == 8)
	{
		ft_putchar_fd(c, 1);
		c = 0;
		p_bit = 0;
		pid = 0;
	}
}

int main(int ac, char **av)
{
	struct sigaction    sin;
	int                 pid;

	pid = getpid();
	ft_putstr_fd(CY "Server PID: \e[0m", 1);
	ft_putnbr_fd(pid, 1);
	ft_putstr_fd("\n" GRN "Waiting...\n" "\e[0m", 1);
	sin.sa_sigaction = bit_to_arr;
	sin.sa_flag = SA_SIGINFO;
	sigaction(SIGUSR1, &sin, NULL);
	sigaction(SIGUSR2, &sin, NULL);
	while (1)
	{
		pause();
	}
	return (0);
}