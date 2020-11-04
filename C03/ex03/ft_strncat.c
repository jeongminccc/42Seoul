/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoi <jechoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 13:38:42 by jechoi            #+#    #+#             */
/*   Updated: 2020/10/27 13:48:22 by jechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	pos;
	char			*ret;

	pos = 0;
	ret = dest;
	while (*dest)
		dest++;
	while (*src && pos < nb)
	{
		*dest = *src;
		dest++;
		src++;
		pos++;
	}
	*dest = '\0';
	return (ret);
}
