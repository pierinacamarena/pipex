/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplitbonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 17:36:47 by pcamaren          #+#    #+#             */
/*   Updated: 2021/10/07 16:41:29 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

char	**ft_malloc_words(char const *s, char c)
{
	char	**str;
	int		i;
	int		size;

	i = 0;
	size = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			size++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	str = (char **)malloc((size + 1) * sizeof(str));
	if (str == 0)
		return (0);
	str[size] = 0;
	return (str);
}

void	ft_malloc_letters(char const *s, char c, char **str)
{
	int		i;
	int		j;
	int		size;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			size = 0;
			while (s[i] != c && s[i])
			{
				size++;
				i++;
			}
			str[j] = (char *)malloc((size + 1) * sizeof(*str));
			if (str[j] == 0)
				return ;
			ft_bzero(str[j], size);
			j++;
		}
		else
			i++;
	}
}

char	**ft_strsplit(char const *s, char c)
{
	int		size;
	int		i;
	int		j;
	char	**str;

	size = 0;
	i = 0;
	if (s == 0)
		return (0);
	str = ft_malloc_words(s, c);
	ft_malloc_letters(s, c, str);
	while (s[i])
	{
		if (s[i] != c)
		{
			j = 0;
			while (s[i] != c && s[i])
				str[size][j++] = s[i++];
			str[size][j] = 0;
			size++;
		}
		else
			i++;
	}
	return (str);
}
