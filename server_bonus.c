/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouftou <obouftou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 19:17:34 by obouftou          #+#    #+#             */
/*   Updated: 2025/02/08 21:45:20 by obouftou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	var_res(int *pid, int *w_bit, char *c, int *buff_i)
{
	*pid = 0;
	*w_bit = 0;
	*c = 0;
	*buff_i = 0;
}

void	print_ack_buff(char *buffer, int *buff_i, int pid)
{
	int	i;

	i = 0;
	while (i < *buff_i)
		ft_putchar_fd(buffer[i++], 1);
	if (buffer[*buff_i - 1] == '\0')
		kill(pid, SIGUSR1);
	*buff_i = 0;
}

void	bit_to_char(int sin, siginfo_t *info, void *context)
{
	static int	pid = 0;
	static int	w_bit = 0;
	static char	c = 0;
	static char	buffer[4] = {0};
	static int	buff_i = 0;

	(void)context;
	if (pid != info->si_pid)
		var_res(&pid, &w_bit, &c, &buff_i);
	pid = info->si_pid;
	if (sin == SIGUSR1)
		c |= (1 << w_bit);
	w_bit++;
	if (w_bit == 8)
	{
		buffer[buff_i++] = c;
		c = 0;
		w_bit = 0;
		if (buff_i == 4 || buffer[buff_i - 1] == '\0')
			print_ack_buff(buffer, &buff_i, pid);
	}
}

int	main(void)
{
	struct sigaction	sin;
	int					pid;

	pid = getpid();
	ft_putstr_fd(CY "Server PID: \e[0m", 1);
	ft_putnbr_fd(pid, 1);
	ft_putstr_fd("\n" GRN "Waiting...\n" "\e[0m", 1);
	sin.sa_sigaction = bit_to_char;
	sin.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sin, NULL);
	sigaction(SIGUSR2, &sin, NULL);
	while (1)
	{
		pause();
	}
	return (0);
}
