/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoi <jechoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 20:56:49 by jechoi            #+#    #+#             */
/*   Updated: 2020/11/04 22:11:35 by jechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void		print_num(long long n)
{
	char c;

	if (n < 0)
	{
		n = -n;
		write(1, "-", 1);
	}
	if (n / 10)
		print_num(n / 10);
	c = '0' + n % 10;
	write(1, &c, 1);
}

int			is_white_space(char c)
{
	if (c == ' ' || (9 <= c && c <= 13))
		return (1);
	return (0);
}

int			ft_atoi(char *str)
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

long long	do_operation(long long l, long long r, char op)
{
	if (op == '+')
		return (l + r);
	if (op == '-')
		return (l - r);
	if (op == '*')
		return (l * r);
	if (op == '/')
		return (l / r);
	if (op == '%')
		return (l % r);
	return (0);
}

int			main(int ac, char **av)
{
	long long	left;
	long long	right;
	char		op;

	if (ac != 4)
		return (0);
	if (av[2][1])
	{
		write(1, "0\n", 2);
		return (0);
	}
	left = ft_atoi(av[1]);
	right = ft_atoi(av[3]);
	op = av[2][0];
	if (right == 0 && op == '/')
		write(1, "Stop : division by zero", 23);
	else if (right == 0 && op == '%')
		write(1, "Stop : modulo by zero", 21);
	else
		print_num(do_operation(left, right, op));
	write(1, "\n", 1);
	return (0);
}
