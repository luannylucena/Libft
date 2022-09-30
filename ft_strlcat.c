/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedeiro <lmedeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 17:54:09 by lmedeiro          #+#    #+#             */
/*   Updated: 2022/09/27 15:55:15 by lmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	src_len;
	size_t	dest_len;
	size_t	i;

	src_len = ft_strlen(src);
	dest_len = ft_strlen(dest);
	if (size == 0) //size = buffer
		return (src_len);//retorna o tamanho da string que deveria copiar.
	if (dest_len + 1 > size) // se o size passado for menor que o tamnho do dest + 1
	//byte referente ao nulo
	{
		return (src_len + size);//retorna isso como se fosse pra dizer o tamanho
		//que realmente é necessário.
	}
	i = 0;
	if (dest_len + 1 <= size)
	{
		while (src[i] && dest_len + i < size - 1)//enquanto a src for verdadeira e o
		//tamanho do dest + o índice da cópia forem menor que o size menos o byte
		//reservado para o nulo.
		{
			dest[dest_len + i] = src[i];//aqui soma-se o 'i' com o dest_len para o final
			//da dest ir avançando conforme recebe a src[i].
			i++;
		} 
		dest[dest_len + i] = '\0';//dest na posição do seu tamanho + os bytes copiados recebe o '\0'.
	}
	return (src_len + dest_len);//após feita a cópia, retorna-se i tamanho da src + dest.
}
