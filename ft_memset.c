/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedeiro <lmedeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 16:01:26 by lmedeiro          #+#    #+#             */
/*   Updated: 2022/10/01 16:46:18 by lmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Preenche uma qte de uma determinada área de memória com um dado valor. Em outras
// palavras, inicializa um objeto.

void	*ft_memset(void *b, int c, size_t len)
{
	char	*p; //ponteiro para o blcoo de memória que será preenchido.

	p = (char *)b;
	while (len > 0)
	{
		p[len - 1] = c;// -1 pq tem que começar a ler da posição certa, começa do zero, se for 4, tem que começar a ler do 3.
		//compensa a terminação '\0' no final da string que não queremos substituir.
		len--;
	}
	return (b);
}
