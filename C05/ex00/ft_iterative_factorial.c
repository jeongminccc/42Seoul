/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoi <jechoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 20:18:14 by jechoi            #+#    #+#             */
/*   Updated: 2020/10/29 20:27:20 by jechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int ret;

	ret = 1;
	if (nb == 0)
		return (1);
	if (nb < 0)
		return (0);
	while (nb)
	{
		ret *= nb;
		nb--;
	}
	return (ret);
}
