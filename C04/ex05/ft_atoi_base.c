/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoi <jechoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 16:17:39 by jechoi            #+#    #+#             */
/*   Updated: 2020/10/29 20:03:40 by jechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*g_base;
int		g_len;

int		is_white_space(char c)
{
	if (c == ' ' || (9 <= c && c <= 13))
		return (1);
	return (0);
}

int		get_idx_base(char c)
{
	int pos;

	pos = 0;
	while (g_base[pos] && g_base[pos] != c)
		pos++;
	if (!g_base[pos])
		return (-1);
	return (pos);
}

int		ft_atoi(char *str)
{
	int ret;
	int m_cnt;
	int idx;

	m_cnt = 0;
	ret = 0;
	while (is_white_space(*str))
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			m_cnt++;
		str++;
	}
	while ((idx = get_idx_base(*str)) != -1)
	{
		ret = (ret * g_len) + idx;
		str++;
	}
	return (m_cnt % 2 ? -ret : ret);
}

int		is_valid_input(char *base)
{
	int len;
	int chk_over;

	len = 0;
	if (!base[len] || !base[len + 1])
		return (0);
	while (base[len])
	{
		if (base[len] == '+' || base[len] == '-' || is_white_space(base[len]))
			return (0);
		chk_over = len + 1;
		while (base[chk_over] && base[len] != base[chk_over])
			chk_over++;
		if (base[chk_over])
			return (0);
		len++;
	}
	return (len);
}

int		ft_atoi_base(char *str, char *base)
{
	int nbr;

	g_base = base;
	if ((g_len = is_valid_input(base)) == 0)
		return (0);
	nbr = ft_atoi(str);
	return (nbr);
}
