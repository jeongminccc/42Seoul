/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoi <jechoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 19:24:21 by jechoi            #+#    #+#             */
/*   Updated: 2020/11/04 19:26:50 by jechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int *ret;
	int idx;

	ret = (int *)malloc(sizeof(int) * length);
	idx = 0;
	while (idx < length)
	{
		ret[idx] = f(tab[idx]);
		idx++;
	}
	return (ret);
}
