/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedeiro <lmedeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 21:18:02 by lmedeiro          #+#    #+#             */
/*   Updated: 2022/09/21 20:21:36 by lmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;
	
	i = 0;
	while (s[i]) // mesma coisa de escrever 's[i] != '\0', escreve assim só pra escrever mais limpo.
	{
		if (s[i] == (char)c) // casting para tratar o 'const' do protótipo.
			return ((char *)s + i); //pq quem anda não é o ponteiro e sim o 'i', então acrescento ele para o ponteiro andar tb.
			i++;
	}
	if ((char)c == '\0') //o nulo tb faz parte, se ele o encontrar, tb retorna o msm da condição de sim.
	{
		return ((char *)s + i);
	}
	return (NULL);//caso não ache o caractere, retorna nulo. ta na definição da função.
}
