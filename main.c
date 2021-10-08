/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 16:44:33 by pcamaren          #+#    #+#             */
/*   Updated: 2021/10/08 16:54:42 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int			ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
		return (0);
}

int	main (int ac, char **av, char **env)
{
	int		fdin;
	int		fdout;
	int		i;
	char	*str;
	int		strncmp1;
	char    *path;
	char    **paths;
	char    *command;
	char    *cmd;

	str = "PATH=";
	command = "wc";
	i = 0;
	if (ac == 5)
	{
		fdin = openfile(av[1], INFILE);
		fdout = openfile(av[4], OUTFILE);
		dup2(fdin, STDIN);
		dup2(fdout, STDOUT);
		printf("fdin is %d and fout %d\n", fdin, fdout);
		printf("env is \n");
		while (env[i])
		{
		    strncmp1 = ft_strncmp(env[i], str, 5);
		    if (strncmp1 == 0)
		        path = env[i];
			i++;
		}
		printf("path is : \n%s\n", path);
		path = path + 5;
		printf("path is : \n%s\n", path);
		paths = ft_strsplit(path, ':');
		i = 0;
		while (paths[i])
		{
			printf("paths[%d] is:  %s\n", i, paths[i]);
			cmd = ft_str3join(paths[i], "/", command);
			printf("cmd is: %s\n", cmd);
			i++;
		}
	}
	else
		write(STDERR, "Invalid number of arguments.\n", 29);
	return (1);
}

int	openfile (char *filename, int mode)
{
	if (mode == INFILE)
	{
		if (access(filename, F_OK))
		{
			write(STDERR, ": No such file or directory\n", 28);
			return (STDIN);
		}
		return (open(filename, O_RDONLY));
	}
	else
		return (open(filename, O_CREAT | O_WRONLY | O_TRUNC,
				S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH));
}
