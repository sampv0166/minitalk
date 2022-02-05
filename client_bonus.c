/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apila-va <apila-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 05:34:08 by apila-va          #+#    #+#             */
/*   Updated: 2022/02/05 12:28:26 by apila-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

void	send_msg(char **argv, int i, int j, int bits)
{
	while (1)
	{
		bits = 8;
		while (bits != 0)
		{
			bits--;
			if ((argv[2][j] >> bits & 1) == 1)
				kill(i, SIGUSR1);
			else
				kill(i, SIGUSR2);
			usleep(100);
		}
		if (argv[2][j] == '\0')
			break ;
		j++;
	}
}

static void	print_ack(int sig, siginfo_t *info, void *nothing)
{
	nothing = NULL;
	info = NULL;
	usleep(100);
	if (sig == SIGUSR1)
		ft_putstr_fd("recieved", 1);
}

void	wait_for_ack(void)
{
	struct sigaction	act;

	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = print_ack;
	if (sigaction(SIGUSR1, &act, NULL) < 0)
	{
		error();
		exit (0);
	}		
}

int	main(int argc, char **argv)
{	
	int					i;
	int					bits;
	int					j;

	j = 0;
	i = ft_atoi(argv[1]);
	bits = 0;
	if (argc != 3 || i <= 0)
		error();
	else
	{
		wait_for_ack();
		send_msg(argv, i, j, bits);
	}
}
