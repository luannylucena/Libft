/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedeiro <lmedeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 18:29:01 by lmedeiro          #+#    #+#             */
/*   Updated: 2022/09/15 22:24:25 by lmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{   
    if (dst && src)//Enquanto os 2 forem veradeiros
    {
        while (len > 0)
        {
            len--;//começa o decremento em cima para que ele não comece no nulo, já que estou usando o próprio len
            ((char *)dst)[len] = ((char *)src)[len];
        }
        return (dst);
    }
    else
    {
        return (NULL);
    }
}
/*
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*swp_dest;
	char	*swp_src;

	swp_dest = (char *) dest;
	swp_src = (char *) src;
	if (dest && src)
	{
		while (n > 0)
		{
			n--;
			swp_dest[n] = swp_src[n];
		}
		return (dest);
	}
	else
	{
		return (NULL);
	}
}*/
int main()
{
    char dst[] = "Love";
    char src[] = "amor";
    char dst1[] = ""; // <""> significa que tem 'nada' dentro =p. Se for NULL, não tem nem nada dentro! 
    char src1[] = "";
    char dst2[] = "Love";
    char src2[] = "Amor";
    char dst3[] = "Lo";
    char src3[] = "Amor";
    
    printf("teste 1\n");
    printf("o valor esperado é: amoe \n");
    printf("%s\n", ft_memmove(dst, src, 5));
    printf("-----------\n");
    printf("teste 2 \n");
    printf("o valor esperado é:");
    printf("%s\n\n\n", ft_memmove(dst1, src1, 1));
    printf("teste 3 \n");
    printf("o valor esperado é: Amor\n");
    printf("%s\n", ft_memmove(dst2, src2, 5));
    printf("-----------\n");
    printf("teste 4 \n");
    printf("o valor esperado é: Amo0z���\n");
    printf("%s\n", ft_memmove(dst3, src3, 3));
}
