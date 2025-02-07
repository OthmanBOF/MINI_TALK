/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouftou <obouftou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 22:27:30 by obouftou          #+#    #+#             */
/*   Updated: 2025/02/07 12:58:42 by obouftou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"


void







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