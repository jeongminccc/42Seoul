/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoi <jechoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 21:58:07 by jechoi            #+#    #+#             */
/*   Updated: 2020/11/04 14:39:13 by jechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

void				ft_strcpy(char *dest, char *src)
{
	while (*src)
		*(dest++) = *(src++);
	*dest = 0;
}

int					get_str_size(char *s)
{
	int ret;

	ret = 0;
	while (*(s++))
		ret++;
	return (ret);
}

struct	s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str *ret;

	ret = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (!ret)
		return (0);
	i = 0;
	while (i < ac)
	{
		ret[i].size = get_str_size(av[i]);
		ret[i].str = (char *)malloc(sizeof(char) * (ret[i].size + 1));
		ret[i].copy = (char *)malloc(sizeof(char) * (ret[i].size + 1));
		ft_strcpy(ret[i].str, av[i]);
		ft_strcpy(ret[i].copy, av[i]);
		i++;
	}
	ret[i].str = 0;
	return (ret);
}
