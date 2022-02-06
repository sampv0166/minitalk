/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apila-va <apila-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 05:33:57 by apila-va          #+#    #+#             */
/*   Updated: 2022/02/07 01:24:55 by apila-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

void	init(int *j, int argc)
{
	*j = 0;
	if (argc != 3)
		error();
}

int	main(int argc, char **argv)
{	
	int	i;
	int	bits;
	int	j;

	init(&j, argc);
	i = ft_atoi(argv[1]);
	while (1)
	{
		bits = 8;
		while (bits != 0)
		{
			bits--;
			if (((unsigned char)argv[2][j] >> bits & 1) == 1)
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
