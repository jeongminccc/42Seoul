/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoi <jechoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 18:48:48 by jechoi            #+#    #+#             */
/*   Updated: 2020/10/28 17:12:37 by jechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int pos;

	pos = 0;
	while (pos < n && src[pos])
	{
		dest[pos] = src[pos];
		pos++;
	}
	while (pos < n)
		dest[pos++] = '\0';
	return (dest);
}
