/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoi <jechoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 16:34:49 by jechoi            #+#    #+#             */
/*   Updated: 2020/10/31 20:33:50 by jechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	g_ans[10];
int		g_cnt_ans;
int		g_diago_l[19];
int		g_diago_r[19];
int		g_row[10];

void	print_ans(void)
{
	write(1, g_ans, 10);
	write(1, "\n", 1);
}

void	set_condition(int row, int col, int val)
{
	g_row[row] = val;
	g_diago_l[col - row + 9] = val;
	g_diago_r[col + row] = val;
}

void	ten_queen(int col)
{
	int row;

	if (col == 10)
	{
		print_ans();
		g_cnt_ans++;
		return ;
	}
	row = 0;
	while (row < 10)
	{
		if (!g_row[row] && !g_diago_l[col - row + 9] && !g_diago_r[col + row])
		{
			set_condition(row, col, 1);
			g_ans[col] = row + '0';
			ten_queen(col + 1);
			set_condition(row, col, 0);
		}
		row++;
	}
}

void	init(void)
{
	int i;

	g_cnt_ans = 0;
	i = 0;
	while (i < 10)
		g_row[i++] = 0;
	i = 0;
	while (i < 19)
	{
		g_diago_l[i] = 0;
		g_diago_r[i] = 0;
		i++;
	}
}

int		ft_ten_queens_puzzle(void)
{
	int ret;

	init();
	ten_queen(0);
	ret = g_cnt_ans;
	return (ret);
}
