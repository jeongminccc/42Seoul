/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainN.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoi <jechoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 09:30:34 by jechoi            #+#    #+#             */
/*   Updated: 2020/10/24 17:42:33 by jechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	rush();
int	is_valid_input(char *c);

int	main(int argc, char **argv)
{
	if (argc != 2 || !is_valid_input(argv[1]) || !rush())
		write(1, "Error\n", 6);
	return (0);
}

// Backtracking Algorithm
