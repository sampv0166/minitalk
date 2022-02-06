/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apila-va <apila-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 05:34:08 by apila-va          #+#    #+#             */
/*   Updated: 2022/02/06 21:33:27 by apila-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk_bonus.h"

void	send_msg(char **argv, int i, int j)
{
	int					bits;

	bits = 0;
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
			usleep(400);
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
	if (sig == SIGUSR1)
		ft_putstr_fd("recieved", 1);
}

int	main(int argc, char **argv)
{	
	int					i;
	int					j;
	struct sigaction	act;

	j = 0;
	if (argc != 3)
		error();
	else
	{
		i = ft_atoi(argv[1]);
		if (i <= 0)
			error();
		act.sa_flags = SA_SIGINFO;
		sigemptyset(&act.sa_mask);
		act.sa_sigaction = print_ack;
		sigaction(SIGUSR1, &act, NULL);
		send_msg(argv, i, j);
	}
}
