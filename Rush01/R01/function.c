/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoi <jechoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 21:02:07 by jechoi            #+#    #+#             */
/*   Updated: 2020/10/24 21:18:00 by jechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** global variables
** - g_input[i] is for getting input values ( ordered by col_up / col_down / row_left / row_right )
*/

int 	   g_input[16];
extern int g_board[5][5];

/*
** make_row(int row, int input_idx, int i)
** - parameter i is the value for check the which number from the first index in board
** - parameter input_idx is the index value for g_input[]
** - seperate case for distinct which condition (col_up? or col_down? or row_left? or row_right?)
** - if condition is col_up, change row index from top to bottom
** - if condition is col_down, change row index from bottom to top
** - remaining case.. row index is fixed
*/

int	make_row(int row, int input_idx, int i)
{
	if (input_idx < 4)
		return (1 + i);
	else if (input_idx < 8)
		return (4 - i);
	else
		return (row);
}

/*
** make_col(int col, int input_idx, int i)
** - parameter's meaning is same as make_row()'s paramater.
** - seperate case for distinct which condition (col_up? or col_down? or row_left? or row_right?)
** - if condition is row_left, change col index from left to right
** - if condition is row_right, change col index from right to left
** - remaining case.. col index is fixed
*/

int	make_col(int col, int input_idx, int i)
{
	if (input_idx < 8)
		return (col);
	else if (input_idx < 12)
		return (1 + i);
	else
		return (4 - i);
}

/*
** is_valid_value_sub(int row, int col, int input_idx)
** - function is used for check each condition (col_up/down, row_left/right) individually
** - if the value has not yet been filled in the board[i][j], treat the conditions as satisfied and
** - fill in the following values.
** - if meet a higher box than highest box that have seen, change the max_val and count
**
** global variables
** - i is index for initialize row index and col index
** - cnt is used for count number of boxes we saw
** - max_val is used for save the highest box's height we saw
*/

int	is_valid_value_sub(int row, int col, int input_idx)
{
	int i;
	int cnt;
	int max_val;

	i = -1;
	cnt = 0;
	max_val = -1;
	while (i++ < 3){
		row = make_row(row, input_idx, i);
		col = make_col(col, input_idx, i);

		if (g_board[row][col] == 0)
			return (1);
		if (max_val < g_board[row][col])
		{
			max_val = g_board[row][col];
			cnt++;
		}
	}
	if (cnt == g_input[input_idx])
		return (1);
	return (0);
}

/*
** is_valid_value(int row, int col)
** - function is used for check four different condition (col_up/down, row _left/right)
** - in case any one in four condition is not satisfied, return false and go back
*/

int	is_valid_value(int row, int col)
{
	int	i;
	int	input_idx;

	i = 0;
	while (i++ < 4)
	{
		if (i < 3)
			input_idx = (i - 1) * 4 + (col - 1);
		else
			input_idx = (i - 1) * 4 + (row - 1);
		if (!is_valid_value_sub(row, col, input_idx))
			return (0);
	}
	return (1);
}

/*
** is_valid_input(char *input)
** - check if input is valid to check input number is between 1 to 4 and if get 16 numbers
** - initialize g_input[i]
*/

int	is_valid_input(char *input)
{
	int cnt;

	cnt = 0;
	while (*input)
	{
		if (cnt >= 16)
			return (0);
		if ('1' <= *input && *input <= '4')
			g_input[cnt++] = *input - '0';
		input++;
	}
	return (cnt == 16);
}
