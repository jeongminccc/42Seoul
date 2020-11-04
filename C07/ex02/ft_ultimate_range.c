/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoi <jechoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 17:51:10 by jechoi            #+#    #+#             */
/*   Updated: 2020/11/01 19:00:05 by jechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int idx;
	int len;

	if (min >= max)
		return (0);
	len = max - min;
	*range = (int *)malloc(sizeof(int) * len);
	if (!*range)
		return (-1);
	idx = 0;
	while (idx < len)
		(*range)[idx++] = min++;
	return (len);
}
