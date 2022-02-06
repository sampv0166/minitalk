/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apila-va <apila-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 05:33:57 by apila-va          #+#    #+#             */
/*   Updated: 2022/02/06 21:05:50 by apila-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

int	main(int argc, char **argv)
{	
	int	i;
	int	bits;
	int	j;

	j = 0;
	i = ft_atoi(argv[1]);
	if (argc != 3 || i <= 0)
		error();
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
