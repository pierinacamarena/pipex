/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 16:44:33 by pcamaren          #+#    #+#             */
/*   Updated: 2021/10/08 16:54:42 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	exec(char *cmd, char **env)
{
	char	**command;
	char	*path;

	command = cmd_split(cmd);
	path = ft_path(command[0], env);
	if (execve(path, command, env) == -1)
	{
		ft_putstr(command[0]);
		ft_putstr(": command not found \n");
		free(path);
		ft_free(command);
		exit(127);
	}
}

void	pipex(char **av, char **env, int fdin)
{
	int		end[2];
	pid_t	child;

	pipe(end);
	child = fork();
	if (child == 0)
	{
		close(end[0]);
		dup2(end[1], STDOUT);
		if (fdin == STDIN)
			exit(1);
		exec(av[2], env);
		close(end[1]);
	}
	else
	{
		waitpid(child, NULL, 0);
		close(end[1]);
		dup2(end[0], STDIN);
		exec(av[3], env);
		close(end[0]);
	}
}

int	main(int ac, char **av, char **env)
{
	int	i;
	int	fdin;
	int	fdout;

	if (ac >= 5)
	{
		fdin = openfile(av[1]);
		fdout = openoutfile(av[ac - 1]);
		if (fdout == -1)
			return (-1);
		dup2(fdin, STDIN);
		dup2(fdout, STDOUT);
		if (ac == 5)
			pipex(av, env, fdin);
		else
		{
			i = 2;
			while (i < ac - 2)
				pipex2(av, env, fdin, i++);
			exec(av[i], env);
		}
	}
	else
		write(STDERR, "Invalid number of arguments.\n", 29);
	return (1);
}

int	openoutfile(char *filename)
{
	if (access(filename, F_OK))
		return (open(filename, O_CREAT | O_WRONLY | O_TRUNC,
				S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH));
	else
	{
		if (access(filename, W_OK))
		{
			ft_putstr("pipex: ");
			ft_putstr(filename);
			ft_putstr(": Permission denied\n");
			return (-1);
		}
		return (open(filename, O_CREAT | O_WRONLY | O_TRUNC,
				S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH));
	}
}

int	openfile(char *filename)
{
	if (access(filename, F_OK))
	{
		ft_putstr("pipex: ");
		ft_putstr(filename);
		ft_putstr(": No such file or directory\n");
		return (STDIN);
	}
	else
	{
		if (access(filename, R_OK))
		{
			ft_putstr("pipex: ");
			ft_putstr(filename);
			ft_putstr(": Permission denied\n");
			return (-1);
		}
		return (open(filename, O_RDONLY));
	}
}
