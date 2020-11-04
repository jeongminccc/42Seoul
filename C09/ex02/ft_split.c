/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoi <jechoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 17:08:34 by jechoi            #+#    #+#             */
/*   Updated: 2020/11/04 17:12:45 by jechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int			is_charset(char c, char *charset)
{
	while (*charset)
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	return (0);
}

long long	get_str_cnt(char *str, char *charset)
{
	long long	ret;
	int			is_start;

	ret = 0;
	is_start = 0;
	while (*str)
	{
		if (!is_charset(*str, charset) && !is_start)
		{
			ret++;
			is_start = 1;
		}
		else if (is_charset(*str, charset))
			is_start = 0;
		str++;
	}
	return (ret);
}

void		ft_strncpy(char *dest, char *src, long long n)
{
	long long idx;

	idx = 0;
	while (idx++ < n)
		*(dest++) = *(src++);
	*dest = 0;
}

char		**ft_split(char *str, char *charset)
{
	char		**ret;
	char		*st;
	long long	idx;
	long long	word_size;

	ret = (char **)malloc(sizeof(char *) * (get_str_cnt(str, charset) + 1));
	idx = 0;
	while (*str)
	{
		st = str;
		word_size = 0;
		while (*str && !is_charset(*(str++), charset))
			word_size++;
		if (word_size == 0)
			continue;
		ret[idx] = (char *)malloc(sizeof(char) * (word_size + 1));
		ft_strncpy(ret[idx++], st, word_size);
	}
	ret[idx] = 0;
	return (ret);
}
