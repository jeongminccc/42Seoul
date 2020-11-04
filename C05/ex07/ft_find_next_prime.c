/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoi <jechoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 16:30:46 by jechoi            #+#    #+#             */
/*   Updated: 2020/10/31 20:44:59 by jechoi           ###   ########.fr       */
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

int	ft_find_next_prime(int nb)
{
	while (!ft_is_prime(nb))
		nb++;
	return (nb);
}
