/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoi <jechoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 16:17:45 by jechoi            #+#    #+#             */
/*   Updated: 2020/10/21 16:48:17 by jechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int i;
	int loop;
	int tmp;

	i = 0;
	while (i < size)
	{
		loop = 0;
		while (loop < size - i - 1)
		{
			if (tab[loop] > tab[loop + 1])
			{
				tmp = tab[loop];
				tab[loop] = tab[loop + 1];
				tab[loop + 1] = tmp;
			}
			loop++;
		}
		i++;
	}
}
