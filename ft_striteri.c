/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedeiro <lmedeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 16:16:05 by lmedeiro          #+#    #+#             */
/*   Updated: 2022/09/30 16:22:12 by lmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//A função vai modificar cada um dos caracteres da string 's', pois aplica em cada ítem
// a função 'f' que foi recebida. 
//Cada caracter é passado por endereço para 'f' para ser modificado se necessário.

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int	i;
	
	i = 0;
	while (s[i]) //enquanto for verdadeiro
	{
		f(i, &s[i]); //A função 'f' aplica 'i' sobre o conteúdo de s[i].
		i++;
	}
	s[i] = '\0';
}
