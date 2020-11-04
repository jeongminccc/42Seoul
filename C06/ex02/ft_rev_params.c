/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoi <jechoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 16:38:39 by jechoi            #+#    #+#             */
/*   Updated: 2020/11/01 16:48:58 by jechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int idx;

	idx = argc - 1;
	while (idx > 0)
	{
		while (*argv[idx])
			write(1, argv[idx]++, 1);
		write(1, "\n", 1);
		idx--;
	}
	return (0);
}
