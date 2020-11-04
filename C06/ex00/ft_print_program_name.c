/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoi <jechoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 21:36:39 by jechoi            #+#    #+#             */
/*   Updated: 2020/11/01 17:24:26 by jechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	argc = 0;
	while (*argv[argc])
		write(1, argv[argc]++, 1);
	write(1, "\n", 1);
	return (0);
}
