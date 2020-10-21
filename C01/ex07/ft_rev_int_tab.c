/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoi <jechoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 15:39:13 by jechoi            #+#    #+#             */
/*   Updated: 2020/10/21 16:17:24 by jechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int pos;
	int tmp;

	pos = 0;
	while (pos < size / 2)
	{
		tmp = tab[pos];
		tab[pos] = tab[size - 1 - pos];
		tab[size - 1 - pos] = tmp;
		pos++;
	}
}
