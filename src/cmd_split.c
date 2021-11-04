/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 15:14:43 by pcamarena         #+#    #+#             */
/*   Updated: 2021/09/07 15:14:44 by pcamarena        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	word_count(const char *str, int *i, int *count)
{
	if (str[*i] == 39)
	{
		(*i)++;
		while (str[*i] != 39 && str[*i] != '\0')
			(*i)++;
		(*count)++;
	}
	else if (str[*i] == 34)
	{
		(*i)++;
		while (str[*i] != 34 && str[*i] != '\0')
			(*i)++;
		(*count)++;
	}
	else
	{
		while (str[*i] != ' ' && str[*i] != '\0')
			(*i)++;
		(*count)++;
	}
}

int	ft_count(const char *str)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != ' ')
			word_count(str, &i, &count);
		if (str[i] == '\0')
			break ;
		else
			i++;
	}
	return (count);
}

int	ft_len(char const *s, char c, int i)
{
	int	len;

	len = 0;
	while (s[i] != '\0' && s[i] != c)
	{
		i++;
		len++;
	}
	return (len);
}

char	**cmd_malloc(char *str, char **cmd, t_splitter *split)
{
	split->i = 0;
	split->j = 0;
	while (str[split->i] && split->j < split->len)
	{
		split->count = 0;
		if (str[split->i] != ' ')
		{
			if (str[split->i] == 39)
				single_quota(str, cmd, split);
			else if (str[split->i] == 34)
				double_quota(str, cmd, split);
			else
				space_case(str, cmd, split);
		}
		cmd[split->j][split->count] = '\0';
		split->i++;
		split->j++;
	}
	cmd[split->j] = NULL;
	return (cmd);
}

char	**cmd_split(const char *str)
{
	t_splitter	split;
	char		**cmd;

	if (str == NULL)
		return (NULL);
	split.len = ft_count(str);
	cmd = ft_calloc(sizeof(char *), split.len + 1);
	if (!cmd)
		return (NULL);
	return (cmd_malloc((char *)str, cmd, &split));
}
