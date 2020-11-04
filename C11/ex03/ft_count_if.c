/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoi <jechoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 19:29:30 by jechoi            #+#    #+#             */
/*   Updated: 2020/11/04 19:31:10 by jechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int (*f)(char*))
{
	int ret;
	int idx;

	ret = 0;
	idx = 0;
	while (idx < length)
	{
		if (f(tab[idx++]))
			ret++;
	}
	return (ret);
}
