/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoi <jechoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 12:42:03 by jechoi            #+#    #+#             */
/*   Updated: 2020/10/28 17:27:27 by jechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int pos;

	pos = 0;
	while (s1[pos] && s2[pos] && pos < n)
	{
		if (s1[pos] != s2[pos])
			return (s1[pos] - s2[pos]);
		pos++;
	}
	if (pos == n || s1[pos] == s2[pos])
		return (0);
	else
		return (s1[pos] - s2[pos]);
}
