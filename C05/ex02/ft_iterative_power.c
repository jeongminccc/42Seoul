/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoi <jechoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 01:34:51 by jechoi            #+#    #+#             */
/*   Updated: 2020/10/31 16:17:56 by jechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int ret;

	ret = 1;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	while (power--)
		ret *= nb;
	return (ret);
}
