/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoi <jechoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 20:56:50 by jechoi            #+#    #+#             */
/*   Updated: 2020/10/17 21:04:48 by jechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_print_comb(void){
	char first, second, third;

	first = '0';
	while(first <= '7'){
		second = first + 1;
		while(second <= '8'){
			third = second + 1;
			while(third <= '9'){
				write(1, &first, 1);
				write(1, &second, 1);
				write(1, &third, 1);
				if(first == '7' && second == '8' && third == '9'){}
				else write(1, ", ", 2);
				third++;
			}
			second++;
		}
		first++;
	}
}
