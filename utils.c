/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 19:28:50 by pcamaren          #+#    #+#             */
/*   Updated: 2021/10/05 19:29:20 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char **cmd_split(char *cmd, char c)
{
	char	**str;
	int	i;
	int	j;
	int	count;

	j = 0;
	count = 0;
	while (cmd[j])
	{
		if (cmd[j] == c)
		{
			count++;
			j++;
		}
	
	}
	str = (char **)malloc(sizeof(char *) * count + 1);
	str[count + 1] = '\0';
	i = 0;
	while (i < count + 1)
	{
		j = 0;
		while (cmd[j] && cmd[j] != c)
			j++;
		str[i] = cmd_up(cmd, j);
		i++;
		cmd = cmd + j + 1;
	}
	return (str);
}

char	*cmd_dup(char *cmd, int n)
{
	char		*command;
	unsigned int	i;

	i = 0;
	command = (char *)malloc(sizeof(char) * n + 1);
	while (i < n)
		command[i++] = *cmd++;
	command[i] = '\0';
	return(command);
} 
