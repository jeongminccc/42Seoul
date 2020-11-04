/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoi <jechoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 17:46:23 by jechoi            #+#    #+#             */
/*   Updated: 2020/11/01 17:58:14 by jechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int *ret;
	int size;
	int idx;

	if (min >= max)
		return (0);
	size = max - min;
	ret = (int *)malloc(sizeof(int) * size);
	idx = 0;
	while (idx < size)
		ret[idx++] = min++;
	return (ret);
}
