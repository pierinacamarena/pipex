/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 19:28:50 by pcamaren          #+#    #+#             */
/*   Updated: 2021/10/07 15:46:16 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*cmd_dup(char *cmd, unsigned int n)
{
	char			*command;
	unsigned int	i;

	i = 0;
	command = (char *)malloc(sizeof(char) * n + 1);
	while (i < n)
		command[i++] = *cmd++;
	command[i] = '\0';
	return (command);
}

int	ft_strsrch(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	if (str[i] == c)
		return (i);
	return (-1);
}

int	ft_strncmp(char *str, char *str2, int n)
{
	while (n > 0 && *str && *str2 && *str == *str2)
	{
		str++;
		str2++;
		n--;
	}
	return (*str2 - *str);
}

char	*joinpath(char *path, char *bin)
{
	char	*joinedstr;
	int		i;
	int		j;
	int		size;

	size = ft_strsrch(path, 0) + ft_strsrch(bin, 0) + 2;
	joinedstr = (char *)malloc(sizeof(char) * size);
	i = 0;
	j = 0;
	while (path[j])
	{
		joinedstr[i] = path[j];
		i++;
		j++;
	}
	joinedstr[i + 1] = '/';
	j = 0;
	while (bin[j])
		joinedstr[i++] = bin[j++];
	joinedstr[i] = 0;
	return (joinedstr);
}

void	ft_putstr(char const *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
}
