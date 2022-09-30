/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedeiro <lmedeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 21:20:24 by lmedeiro          #+#    #+#             */
/*   Updated: 2022/09/27 21:42:59 by lmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_counter(const char *s, char c)
{
	int		count;
	size_t	i;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static int	ft_len(const char *s, char c)
{
	size_t	len;

	len = 0;
	while (*s && *s != c)
	{
		len++;
		s++;
	}
	return (len);
}

char	**ft_split(char const *str, char c)
{
	int		i;
	int		j;
	char	**result;

	i = 0;
	result = (char **)ft_calloc((ft_counter(str, c) + 1), sizeof(char *));
	if (!result)
		return (NULL);
	while (*str)
	{
		while (*str == c)
			str++;
		if (*str)
		{
			result[i] = (char *)ft_calloc((ft_len(str, c) + 1), sizeof(char));
			if (!result[i])
				return (NULL);
			j = 0;
			while (*str != c && *str)
				result[i][j++] = *str++;
			i++;
		}
	}
	return (result);
}
