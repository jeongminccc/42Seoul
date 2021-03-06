/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_any.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoi <jechoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 19:27:18 by jechoi            #+#    #+#             */
/*   Updated: 2020/11/04 19:29:04 by jechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_any(char **tab, int (*f)(char*))
{
	int idx;

	idx = 0;
	while (tab[idx])
	{
		if (f(tab[idx]))
			return (1);
		idx++;
	}
	return (0);
}
