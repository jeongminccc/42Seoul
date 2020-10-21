/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoi <jechoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 21:46:50 by jechoi            #+#    #+#             */
/*   Updated: 2020/10/21 13:23:55 by jechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char c_buf[10];
int c_len;
int a;

void recur(char c, int cnt){
	if(cnt == c_len - 1){
		write(1, c_buf, c_len);
		if(c_buf[0] == ('0' + (10 - c_len))){}
		else write(1, ", ", 2);
		return;
	}

	while(c <= '0' + (10 - c_len + cnt)){
		c_buf[cnt+1] = ++c;
		recur(c, cnt + 1);
	}
}

void ft_print_combn(int n){
	int pos;
	c_len = n;

	pos = 0;
	c_buf[0] = '0';
	while(c_buf[0] <= '0' + (10 - n)){
		recur(c_buf[0], 0);
		c_buf[0]++;
	}
}
