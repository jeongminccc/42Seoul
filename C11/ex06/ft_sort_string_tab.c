/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoi <jechoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 21:23:51 by jechoi            #+#    #+#             */
/*   Updated: 2020/11/04 21:56:43 by jechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

long long	get_tab_cnt(char **tab)
{
	long long ret;

	ret = 0;
	while (*(tab++))
		ret++;
	return (ret);
}

void		ft_sort_string_tab(char **tab)
{
	char	*tmp;
	int		idx;
	int		i;
	int		size;

	i = 0;
	size = get_tab_cnt(tab);
	while (i < size)
	{
		idx = 0;
		while (idx < size - i - 1)
		{
			if (ft_strcmp(tab[idx], tab[idx + 1]) > 0)
			{
				tmp = tab[idx];
				tab[idx] = tab[idx + 1];
				tab[idx + 1] = tmp;
			}
			idx++;
		}
		i++;
	}
}
