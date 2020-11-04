/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoi <jechoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 21:57:44 by jechoi            #+#    #+#             */
/*   Updated: 2020/11/04 15:00:29 by jechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_hexa(unsigned char c)
{
	c += '0';
	if (c > '9')
		c = 'a' + (c - '9' - 1);
	write(1, &c, 1);
}

void	hexa(unsigned char c)
{
	write(1, "\\", 1);
	print_hexa((int)c / 16);
	print_hexa((int)c % 16);
}

void	ft_putstr_non_printable(char *str)
{
	while (*str)
	{
		if (' ' <= *str && *str <= '~')
			write(1, str, 1);
		else
			hexa(*str);
		str++;
	}
}

int main()
{
	ft_putstr_non_printable("abc");
	return 0;
}
