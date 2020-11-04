/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoi <jechoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 11:55:33 by jechoi            #+#    #+#             */
/*   Updated: 2020/10/28 12:08:42 by jechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	recur(int n)
{
	char c;

	if (n)
	{
		recur(n / 10);
		c = '0' + n % 10;
		write(1, &c, 1);
	}
}

void	ft_putnbr(int nb)
{
	char c;

	if (nb < 0)
	{
		write(1, "-", 1);
		c = '0' + -(nb % 10);
		recur(-(nb / 10));
	}
	else
	{
		c = '0' + (nb % 10);
		recur(nb / 10);
	}
	write(1, &c, 1);
}
