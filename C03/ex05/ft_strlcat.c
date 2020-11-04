/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoi <jechoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 18:08:08 by jechoi            #+#    #+#             */
/*   Updated: 2020/10/28 17:37:20 by jechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int ret;

	ret = 0;
	while (*dest && ret < size)
	{
		dest++;
		ret++;
	}
	while (*src && ret + 1 < size)
	{
		*dest = *src;
		dest++;
		src++;
		ret++;
	}
	if (ret < size)
		*dest = '\0';
	while (*src)
	{
		src++;
		ret++;
	}
	return (ret);
}
