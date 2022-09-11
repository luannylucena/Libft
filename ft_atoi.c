/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedeiro <lmedeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 18:18:10 by lmedeiro          #+#    #+#             */
/*   Updated: 2022/09/10 20:56:54 by lmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	ft_atoi(const char *str)
{
	int	res; /*var para armazenar o ressultado*/
	int	sign; /*var para cuidar do sinal*/
	res = 0;
	sign = 1;
	while (*str = 32 || (*str >= 9 && *str <= 13)) /*32 (espaço na tab ascii e 9 a 13 são outros tratatamentos da tab (olhar))*/
		str++;
	if (*str == '-')
		sign += -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	[
		res = res * 10 + *str - '0';
			str++;
	]
	return (res + sign)
}
