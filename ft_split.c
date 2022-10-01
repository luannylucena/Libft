/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedeiro <lmedeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 21:20:24 by lmedeiro          #+#    #+#             */
/*   Updated: 2022/10/01 16:16:58 by lmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Picota `s` em várias strings utilizando `c` como um delimitador, deve ter nulo em cada string.
// Retorna as strings ou nulo se a alocação falhar.
// Resuimndo, a função cria um array de strings que foram criadas pela subdivisão da string
// 's' passada como argumento, cada vez que o caracter c é encontrado.

static int	lenuc(const char *s, char c) //lenuc = 'len' até 'c';
{
    int	len;

    len = 0;
    while (s[len] != c && s[len]) //vai contar o números de caracters.
        len++;
    return (len);
}

static int	nmbr_of_word(const char *s, char c)
{
    int	count;
    int	i;

    i = 0;
    count = 0;
    while (s[i])
    {
        while (s[i] == c) //isso funciona apenas para que o 'i' saia do espaço e rode para o próximo 'while';
            i++;
        if (s[i])
        {
            while (s[i] != c && s[i])
                i++; //vai rodando, qdo encontra o 'c' (espaço), ele sai do laço e dá Count++, então conta uma palavra.
            count++;
        }
    }
    return (count);
}

char	**ft_split(char const *s, char c)
{
    int		i;
    int		j;
    char	**splitstr;

    i = 0;
    splitstr = (char **)ft_calloc((nmbr_of_word(s, c) + 1), sizeof(char *)); //aqui é o ponteiro que aponta para o ponteiro de baixo.
	//Um ponteiro de ponteiro cria uma tabela. 
    if (!splitstr)
        return (NULL);
    while (*s)
    {
        while (*s == c) //aqui serve novamente apenas para sair do 'C' (espaço) e entrar na próxima condição;
            s++;
        if (*s)
        {
            splitstr[i] = (char *)ft_calloc((lenuc(s, c) + 1), sizeof(char));
            if (!splitstr[i])
                return (NULL);
            j = 0;
            while (*s != c && *s)
                splitstr[i][j++] = *s++; //aqui vai passando a string pro ponteiro 'splitstr' e vai juntando as palavras com os caracteres;
            i++; //roda pra sair da condição e ir lá pra cima novamente;
        }
    }
    return (splitstr);
}