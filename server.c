/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apila-va <apila-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 05:33:01 by apila-va          #+#    #+#             */
/*   Updated: 2022/02/06 20:51:34 by apila-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

static void	print_client_msg(int sig, siginfo_t *info, void *nothing)
{
	static unsigned char	c;
	static size_t			size;
	unsigned int			i;

	nothing = NULL;
	info = NULL;
	if (sig == SIGUSR2)
		sig = 0;
	else if (sig == SIGUSR1)
		sig = 1;
	if (c == 0 && size == 0)
		size = 8;
	size--;
	i = ((sig & 1) << size);
	c = c + i;
	if (size == 0)
	{
		if (c == 0)
			ft_putstr_fd("\n", 1);
		ft_putchar_fd(c, 1);
		size = 8;
		c = 0;
	}
}

int	main(void)
{
	size_t				pid;
	struct sigaction	act;

	act.sa_flags = SA_SIGINFO;
	sigemptyset(&act.sa_mask);
	act.sa_sigaction = print_client_msg;
	pid = getpid();
	ft_putstr_fd("pid = ", 1);
	ft_putnbr_fd(pid, 1);
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	while (1)
		;
	return (0);
}
