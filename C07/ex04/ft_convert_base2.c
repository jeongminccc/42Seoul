/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoi <jechoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 19:22:39 by jechoi            #+#    #+#             */
/*   Updated: 2020/11/02 20:06:19 by jechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		is_w_space(char c);

int		get_nbr_len(long long nbr, int len)
{
	int ret;

	if (nbr == 0)
		return (1);
	ret = 0;
	if (nbr < 0)
		ret++;
	while (nbr)
	{
		nbr /= len;
		++ret;
	}
	return (ret);
}

char	*ft_putnbr(long long nbr, char *base, int base_len)
{
	char	*ret;
	int		ret_size;

	ret_size = get_nbr_len(nbr, base_len);
	ret = (char *)malloc(sizeof(char) * (ret_size + 1));
	ret[ret_size--] = 0;
	if (nbr < 0)
	{
		nbr = -nbr;
		ret[0] = '-';
	}
	if (nbr == 0)
		ret[0] = base[0];
	while (nbr)
	{
		ret[ret_size--] = base[nbr % base_len];
		nbr /= base_len;
	}
	return (ret);
}

int		is_valid(char *base, int *len)
{
	int chk_over;

	*len = 0;
	if (!base[*len] || !base[*len + 1])
		return (0);
	while (base[*len])
	{
		if (base[*len] == '+' || base[*len] == '-' || is_w_space(base[*len]))
			return (0);
		chk_over = *len + 1;
		while (base[chk_over] && base[*len] != base[chk_over])
			chk_over++;
		if (base[chk_over])
			return (0);
		(*len)++;
	}
	return (1);
}
