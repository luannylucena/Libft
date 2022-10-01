/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedeiro <lmedeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 15:31:20 by lmedeiro          #+#    #+#             */
/*   Updated: 2022/10/01 16:41:23 by lmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// A função procura a primeira ocorrência do valor 'C' ( 0 a 255) nos primeiros 'counts'
// bytes do buffer de memória apontados por *s. Ela pára qdo já encontrou C ou qdo 
// já examinou 'coount' bytes.

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned char	value;
	size_t			i;

	ptr = (unsigned char *) s;
	value = (unsigned char) c;
	i = 0;
	while (i < n)
	{
		if (ptr[i] == value)
			return (&ptr[i]);
		i++;
	}
	return (NULL);
}
