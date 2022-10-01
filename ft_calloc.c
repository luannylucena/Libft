/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedeiro <lmedeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 15:11:24 by lmedeiro          #+#    #+#             */
/*   Updated: 2022/10/01 16:30:33 by lmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Cria um vetor de tamanho dinâmico, isto é, este tamanho é definido durante a execução do programa.
// Difere da função malloc, pois além de inicializar os espaços de memória, ainda atribui o valor 'zero'
// para cada um deles.

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	
	if (size > 2147483647)
		return (NULL);
	ptr = (void *)malloc(count * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, count * size);
	return (void *)ptr;
}
