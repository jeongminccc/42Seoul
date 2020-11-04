/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoi <jechoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 19:31:39 by jechoi            #+#    #+#             */
/*   Updated: 2020/11/04 20:40:20 by jechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int idx;
	int f_ret;
	int is_ascend;
	int is_descend;

	idx = 0;
	is_ascend = 0;
	is_descend = 0;
	while (idx < length - 1)
	{
		f_ret = f(tab[idx], tab[idx + 1]);
		if (f_ret < 0)
			is_ascend++;
		if (f_ret > 0)
			is_descend++;
		idx++;
	}
	if (!is_ascend || !is_descend)
		return (1);
	return (0);
}
