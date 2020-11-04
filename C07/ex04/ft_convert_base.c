/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoi <jechoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 19:22:39 by jechoi            #+#    #+#             */
/*   Updated: 2020/11/02 20:06:07 by jechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		is_valid(char *base, int *len);
char	*ft_putnbr(long long nbr, char *base, int base_len);

int		is_w_space(char c)
{
	if (c == ' ' || (9 <= c && c <= 13))
		return (1);
	return (0);
}

int		get_idx_base(char c, char *base)
{
	int pos;

	pos = 0;
	while (base[pos] && base[pos] != c)
		pos++;
	if (!base[pos])
		return (-1);
	return (pos);
}

int		ft_atoi(char *str, char *base, int len)
{
	int ret;
	int m_cnt;
	int idx;

	m_cnt = 0;
	ret = 0;
	while (is_w_space(*str))
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			m_cnt++;
		str++;
	}
	while ((idx = get_idx_base(*str, base)) != -1)
	{
		ret = (ret * len) + idx;
		str++;
	}
	return (m_cnt % 2 ? -ret : ret);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		num;
	int		len_from;
	int		len_to;
	char	*ret;

	if (!(is_valid(base_from, &len_from)) || !(is_valid(base_to, &len_to)))
		return (0);
	num = ft_atoi(nbr, base_from, len_from);
	ret = ft_putnbr(num, base_to, len_to);
	return (ret);
}
