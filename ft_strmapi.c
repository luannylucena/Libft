/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedeiro <lmedeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 17:24:31 by lmedeiro          #+#    #+#             */
/*   Updated: 2022/10/01 17:00:59 by lmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// essa função aloca e copia os membros da string 's' passados pela função f
// em uma nova string

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*new_str;
	int		i;

	i = 0;
	new_str = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (new_str == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		new_str[i] = f(i, s[i]); // // a nova string na posição i recebe..
		// a ação da função f que aplica o índice i sobre o valor da string s na posição i.
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
