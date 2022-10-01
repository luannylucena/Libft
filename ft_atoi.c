/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedeiro <lmedeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 18:18:10 by lmedeiro          #+#    #+#             */
/*   Updated: 2022/10/01 16:25:35 by lmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	ft_atoi(const char *str)
{
	int	res;
	int	sign;

	res = 0;
	sign = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13)) // se o início da string for espaço, ou qualquer
	//caracter de tabulação, simplesmente seguimos em frente.
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
		sign = -1; 
		str++;
	}
	while (*str >= '0' && *str <= '9') //enquanto for um número inteiro.
	{
		res = res * 10 + *str - '0'; //Multiplicamos 10 por nosso 'res' para configurar o posicionamento do dígito onde ele deveria estar
			str++;
	}
	return (res * sign); //supondo que a string tenha um negativo (tststs-18) ele vai se tornar -1 la no final, pq precisa msm, pq ele é neagtivo msm!
}
