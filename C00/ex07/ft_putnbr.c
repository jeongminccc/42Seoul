/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoi <jechoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 21:28:44 by jechoi            #+#    #+#             */
/*   Updated: 2020/10/21 12:44:19 by jechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void recur(int n){
	if(n == 0) return;

	char c;
	c = '0' + n % 10;
	recur(n/10);
	write(1, &c, 1);
}

void ft_putnbr(int nb){
	char front;

	if(nb == 0) {
		write(1, "0", 1);
		return;
	}
	if(nb < 0) {
		write(1, "-", 1);
		front = '0' + -(nb%10);
		recur(-(nb/10));
		write(1, &front, 1);
	}
	else recur(nb);
}
