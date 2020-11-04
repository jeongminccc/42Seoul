/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoi <jechoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 21:58:54 by jechoi            #+#    #+#             */
/*   Updated: 2020/11/04 22:04:38 by jechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long long	get_tab_cnt(char **tab)
{
	long long ret;

	ret = 0;
	while (*(tab++))
		ret++;
	return (ret);
}

void		ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
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
			if (cmp(tab[idx], tab[idx + 1]) > 0)
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
