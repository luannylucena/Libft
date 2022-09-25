/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedeiro <lmedeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 18:46:27 by lmedeiro          #+#    #+#             */
/*   Updated: 2022/09/22 21:57:07 by lmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int	i;
	unsigned int	j;

	if (*needle == '\0')
		return ((char *) haystack);
	i = 0;
	while (haystack[i] && i < len)
	{
		j = 0;
		while (haystack[i + j] == needle[j] && (i + j) < len)
		{
			j++;
			if (needle[j] == '\0')
				return ((char *) &(haystack[i]));//qdo ele encontra o needle dentro do hast, ele soma no contador do needle e encontra o '/0', dai retorna o ponteiro do hast, como no ex abaixo.
		}
		i++;
	}
	return (NULL);// se por um acaso tiver uma letra diferente "ovk", a needle não é igual ao hast, então retorno nulo.
}

/*
int main()
{
    printf("%s", ft_strnstr("lovelove", "ov", 3));

}*/