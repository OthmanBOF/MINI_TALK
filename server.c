/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouftou <obouftou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 22:27:30 by obouftou          #+#    #+#             */
/*   Updated: 2025/02/06 22:13:03 by obouftou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int main(int ac, char **av)
{
    struct sigaction    sig;
    int                 pid;

    pid = getpid();
    ft_putstr_fd(CY "Server PID: \e[0m", 1);
	ft_putnbr_fd(pid, 1);
	ft_putstr_fd("\n" GRN "Waiting...\n" "\e[0m", 1);
    
}