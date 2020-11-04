/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoi <jechoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 16:49:18 by jechoi            #+#    #+#             */
/*   Updated: 2020/11/01 17:13:34 by jechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strcmp(char *a, char *b)
{
	while (*a && *b)
	{
		if (*a != *b)
			return (*a - *b);
		a++;
		b++;
	}
	return (*a - *b);
}

void	sort_params(int ac, char **av)
{
	int		i;
	int		j;
	char	*tmp;

	i = 1;
	while (i < ac)
	{
		j = 1;
		while (j < ac - i)
		{
			if (ft_strcmp(av[j], av[j + 1]) > 0)
			{
				tmp = av[j];
				av[j] = av[j + 1];
				av[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

int		main(int argc, char **argv)
{
	int idx;

	sort_params(argc, argv);
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
