/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoi <jechoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 16:25:39 by jechoi            #+#    #+#             */
/*   Updated: 2020/10/31 20:44:42 by jechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	long long idx;

	if (nb <= 1)
		return (0);
	if (nb <= 3)
		return (1);
	idx = 2;
	while (idx * idx <= nb)
	{
		if (nb % idx == 0)
			return (0);
		idx++;
	}
	return (1);
}
