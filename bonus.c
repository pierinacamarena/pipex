/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 17:16:07 by pcamaren          #+#    #+#             */
/*   Updated: 2021/10/06 17:26:17 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	openfile(char *file, char c)
{
	if (c == 'i')
	{
		if (access(file, F_OK))
		{
			write(STDERR, "File or directory not found\n", 28);
			return (STDIN);
		}
		else
			return(open(file, O_RDONLY));
	}
	else if (c == 'o')
	{
		if (access(file, W_OK))
		{
			write(STDERR, "Cannot write to file\n", 21);
			return (STDIN);
		}
		else
			return(open(file, O_CREAT | O_WRONLY | O_TRUNC | S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH));
	}
	return (-1);
}

char	*getPath (char *cmd, char **env)
{
	char	*path;
	char	*dir;
	char	*bin;
	int		i;

	i = 0;
	while (env[i] && ft_strncmp(env[i], "PATH=", 5))
		i++;
	if (!env[i])
		return (cmd);
	path = env[i] + 5;
	while (path && ft_strsrch(path, ':') > -1)
	{
		dir = cmd_dup(path, ft_strsrch(path, ':'));
		bin = joinpath(dir, cmd);
		free(dir);
		if (access(bin, F_OK) == 0)
			return (bin);
		free(bin);
		path += ft_strsrch(path, ':') + 1;
	}
	return (cmd);
}

void	exec (char *cmd, char **env)
{
	char	**args;
	char	*path;

	args = cmd_split(cmd, ' ');
	if (ft_strsrch(args[0], '/') > -1)
		path = args[0];
	else
		path = getPath(args[0], env);
	execve(path, args, env);
	write(STDERR, "pipex: ", 7);
	write(STDERR, cmd, ft_strsrch(cmd, 0));
	write(STDERR, ": command not found\n", 20);
	exit(127);
}

void	redir (char *cmd, char **env, int fdin)
{
	pid_t	pid;
	int		pipefd[2];

	pipe(pipefd);
	pid = fork();
	if (pid)
	{
		close(pipefd[1]);
		dup2(pipefd[0], STDIN);
		waitpid(pid, NULL, 0);
	}
	else
	{
		close(pipefd[0]);
		dup2(pipefd[1], STDOUT);
		if (fdin == STDIN)
			exit(1);
		else
			exec(cmd, env);
	}
}

int	main (int ac, char **av, char **env)
{
	int	fdin;
	int	fdout;
	int	i;

	i = 3;
	if (ac >= 5)
	{
		fdin = openfile(av[1], 'i');
		fdout = openfile(av[ac - 1], 'o');
		dup2(fdin, STDIN);
		dup2(fdout, STDOUT);
		redir(av[2], env, fdin);
		while (i < ac - 2)
			redir(av[i++], env, 1);
		exec(av[i], env);
	}
	else
		write(STDERR, "Invalid number of arguments.\n", 29);
	return (1);
}
