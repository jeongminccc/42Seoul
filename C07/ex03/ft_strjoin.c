/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoi <jechoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 18:26:34 by jechoi            #+#    #+#             */
/*   Updated: 2020/11/01 19:21:56 by jechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void		ft_strcat(char *dest, char *src)
{
	while (*dest)
		dest++;
	while (*src)
		*(dest++) = *(src++);
	*dest = 0;
}

long long	ft_strlen(char *s)
{
	long long ret;

	ret = 0;
	while (s[ret])
		ret++;
	return (ret);
}

char		*ft_strjoin(int size, char **strs, char *sep)
{
	int			idx;
	long long	ret_len;
	char		*ret;

	if (size <= 0)
	{
		ret = (char *)malloc(1);
		ret[0] = 0;
		return (ret);
	}
	ret_len = 0;
	idx = 0;
	while (idx < size)
		ret_len += ft_strlen(strs[idx++]);
	ret_len += ft_strlen(sep) * (size - 1);
	ret = (char *)malloc(sizeof(char) * (ret_len + 1));
	ret[0] = 0;
	idx = 0;
	while (idx < size)
	{
		ft_strcat(ret, strs[idx]);
		if ((idx++) != size - 1)
			ft_strcat(ret, sep);
	}
	return (ret);
}
