/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoi <jechoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 20:38:25 by jechoi            #+#    #+#             */
/*   Updated: 2020/10/21 21:22:11 by jechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_lower(char c)
{
	if ('a' <= c && c <= 'z')
		return (1);
	return (0);
}

int		is_upper(char c)
{
	if ('A' <= c && c <= 'Z')
		return (1);
	return (0);
}

int		is_words(char c)
{
	if ('0' <= c && c <= '9')
		return (1);
	if (is_lower(c) || is_upper(c))
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	pos;
	int	isfirst;

	pos = 0;
	isfirst = 0;
	while (str[pos])
	{
		if (!is_words(str[pos]))
			isfirst = 0;
		else
		{
			if (!isfirst && is_lower(str[pos]))
				str[pos] -= 32;
			else if (isfirst && is_upper(str[pos]))
				str[pos] += 32;
			isfirst = 1;
		}
		pos++;
	}
	return (str);
}
