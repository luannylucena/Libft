/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedeiro <lmedeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 18:29:01 by lmedeiro          #+#    #+#             */
/*   Updated: 2022/10/01 15:42:16 by lmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Copia 'len' bytes da string 'src' para a string 'dst';

void	*ft_memmove(void *dst, const void *src, size_t len)
{   
 	if (src > dst)
	{
		ft_memcpy(dst, src, len);// começo da esquerda pra direita
	}
	else 
	{
		while (len > 0) // o 'len' aqui já vai começar minha leitura do final da string.
		{
			len--;
			((char *)dst)[len] = ((char *)src)[len];//direita pra esquerda, pq começo do 'len'.
		}	
	}
	return (dst);
}
