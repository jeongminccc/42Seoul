/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoi <jechoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 17:38:23 by jechoi            #+#    #+#             */
/*   Updated: 2020/11/01 17:55:46 by jechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

long long		ft_strlen(char *s)
{
	long long ret;

	ret = 0;
	while (s[ret])
		ret++;
	return (ret);
}

char			*ft_strdup(char *src)
{
	char			*ret;
	long long		idx;
	long long		len;

	len = ft_strlen(src);
	ret = (char *)malloc(sizeof(char) * (len + 1));
	idx = -1;
	while (++idx < len)
		ret[idx] = src[idx];
	ret[idx] = '\0';
	return (ret);
}
