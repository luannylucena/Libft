/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedeiro <lmedeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 17:30:33 by lmedeiro          #+#    #+#             */
/*   Updated: 2022/09/29 19:17:51 by lmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Esta função aloca memória e retorna uma string 'fresca' de caracteres terminada 
//com um '\0' que é o equivalente char do int passado no parâmetro. Os números negativos 
//também devem ser gerenciados. Se a alocação falhar, a função retornará NULL. 
static void get_result(long int n, char *str, int *i, int *bytes)
{
	if (*bytes == 2) //2 é de '-' e '\0'
		str[0] = '-';
	while (*i >= 0)
	{
		if (*bytes == 2 && (*i) == 0)//qdo for negativo e a posição estiver na casa 0 (zero - que é a do sinal)
		//ele vai parar (break), pq nada pode ocupar a casa do sinal.
			break;
		str[*i] = (n % 10) + '0';
		n = n - n % 10;
		n = n / 10;
		(*i)--; 
	}	
}

static int	countdigits(long int n)// é long pro caso de ser o número máximo?
{
	int	count;

	count = 1;//pq não existe dígito negativo. =p
	while (n >= 10)
	{
		n = n /10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	long int	long_n;
	int			digits;
	int			i;
	int			bytes_to_alloc;
	char		*str;

	long_n = n;
	if (n < 0)
	{
		bytes_to_alloc = 2; // '-' e '\0'
		long_n = long_n * -1;
	}
	else
		bytes_to_alloc = 1; //apenas o '\0'
	digits = countdigits(long_n);
	str = malloc(digits + bytes_to_alloc);
	if (!str)
		return (NULL);
	i = digits + bytes_to_alloc - 1;
	str[i] = '\0';
	i--;
	get_result(long_n, str, &i, &bytes_to_alloc);
	return (str);
}
