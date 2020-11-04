/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoi <jechoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 17:51:02 by jechoi            #+#    #+#             */
/*   Updated: 2020/10/29 16:06:02 by jechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*g_base;
int		g_len;

int		is_valid_input(char *input)
{
	int len;
	int check_over;

	len = 0;
	if (!input[len] || !input[len + 1])
		return (0);
	while (input[len])
	{
		if (input[len] == '+' || input[len] == '-')
			return (0);
		check_over = len + 1;
		while (input[check_over] && input[len] != input[check_over])
			check_over++;
		if (input[check_over])
			return (0);
		len++;
	}
	return (len);
}

void	print_base(int n)
{
	char c;

	if (n)
	{
		print_base(n / g_len);
		c = g_base[n % g_len];
		write(1, &c, 1);
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	char c;

	g_base = base;
	if (!(g_len = is_valid_input(base)))
		return ;
	if (nbr < 0)
	{
		write(1, "-", 1);
		print_base(-(nbr / g_len));
		c = g_base[-(nbr % g_len)];
	}
	else
	{
		print_base(nbr / g_len);
		c = g_base[nbr % g_len];
	}
	write(1, &c, 1);
}
