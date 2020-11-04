/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoi <jechoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 13:48:54 by jechoi            #+#    #+#             */
/*   Updated: 2020/10/28 17:29:33 by jechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	char *temp_str;
	char *temp_find;

	if (*to_find == '\0')
		return (str);
	while (*str)
	{
		if (*str == *to_find)
		{
			temp_str = str;
			temp_find = to_find;
			while (*temp_find && *temp_str == *temp_find)
			{
				temp_find++;
				temp_str++;
			}
			if (*temp_find == '\0')
				return (str);
		}
		str++;
	}
	return (0);
}
