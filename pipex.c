/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 17:36:47 by pcamaren          #+#    #+#             */
/*   Updated: 2021/10/07 16:41:29 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pipex.h"

void	exec(char *cmd, char **env)
{
	char	**command;
	char	*path;

	command = ft_strsplit(cmd, ' ');
	path = ft_path(command[0], env);
	if (execve(path, command, env) == -1)
	{
		printf("command not found \n");
		free(path);
		ft_free(command);
		exit(1);
	}
}

void	pipex(char **av, char **env, int fdin)
{
	int	end[2];
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
	int	fdin;
	int	fdout;

	if (ac == 5)
	{
		fdin = openfile(av[1], INFILE);
		fdout = openfile(av[4], OUTFILE);
		dup2(fdin, STDIN);
		dup2(fdout, STDOUT);
		pipex(av, env, fdin);
		close(fdin);
		close(fdout);
	}
	else
		write(STDERR, "Invalid number of arguments.\n", 29);
	return (1);
}

int	openfile(char *filename, int mode)
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
