/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 17:36:47 by pcamaren          #+#    #+#             */
/*   Updated: 2021/10/26 18:41:29 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pipex.h"

char	*ft_path(char *arg, char **env)
{
	int		finder;
	int		i;
	char	*path;
	char	*cmd;
	char	**path_split;

	i = 0;
	while (env[i])
	{
		finder = ft_strncmp(env[i], "PATH=", 5);
		if (finder == 0)
			path = env[i];
		i++;
	}
	path = path + 5;
	path_split = ft_strsplit(path, ':');
	i = 0;
	cmd = cmd_tester(path_split, arg);
	if (cmd)
		return (cmd);
	ft_free(path_split);
	return (NULL);
}

char	*cmd_tester(char **path_split, char *arg)
{
	int	i;
	int	j;
	char	*cmd;

	i = 0;
	while (path_split[i])
	{
		j = ft_strlen(path_split[i]) - 1;
		if (path_split[i][j] == '/')
			cmd = ft_strjoin(path_split[i], arg);
		else
			cmd = ft_str3join(path_split[i], "/", arg);
		if (access(cmd, F_OK | X_OK) == 0)
		{
			ft_free(path_split);
			return (cmd);
		}
		free(cmd);
		i++;
	}
	return (NULL);
}
