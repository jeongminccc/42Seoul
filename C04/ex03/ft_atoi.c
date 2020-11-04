/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoi <jechoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 12:09:11 by jechoi            #+#    #+#             */
/*   Updated: 2020/10/28 17:47:18 by jechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_white_space(char c)
{
	if (c == ' ' || (9 <= c && c <= 13))
		return (1);
	return (0);
}

int	ft_atoi(char *str)
{
	int ret;
	int m_cnt;

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
	while ('0' <= *str && *str <= '9')
	{
		ret = (ret * 10) + (*str - '0');
		str++;
	}
	return (m_cnt % 2 ? -ret : ret);
}
