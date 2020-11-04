/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoi <jechoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 21:23:53 by jechoi            #+#    #+#             */
/*   Updated: 2020/10/28 18:59:58 by jechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int pos;

	pos = 0;
	while (src[pos] && pos + 1 < size)
	{
		dest[pos] = src[pos];
		pos++;
	}
	dest[pos] = '\0';
	while (src[pos])
		pos++;
	return (pos);
}
