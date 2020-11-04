/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoi <jechoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 13:59:50 by jechoi            #+#    #+#             */
/*   Updated: 2020/11/04 14:33:10 by jechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

void	print_num(int n)
{
	char c;

	if (n / 10)
		print_num(n / 10);
	c = '0' + (n % 10);
	write(1, &c, 1);
}

void	ft_show_tab(struct s_stock_str *par)
{
	while (par->str)
	{
		write(1, par->str, par->size);
		write(1, "\n", 1);
		print_num(par->size);
		write(1, "\n", 1);
		write(1, par->copy, par->size);
		write(1, "\n", 1);
		par++;
	}
}
