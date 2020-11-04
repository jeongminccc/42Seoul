/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoi <jechoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 21:50:12 by jechoi            #+#    #+#             */
/*   Updated: 2020/11/01 16:48:29 by jechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int idx;

	idx = 1;
	while (idx < argc)
	{
		while (*argv[idx])
			write(1, argv[idx]++, 1);
		write(1, "\n", 1);
		idx++;
	}
	return (0);
}
