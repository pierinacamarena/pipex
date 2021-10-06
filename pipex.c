/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 17:36:47 by pcamaren          #+#    #+#             */
/*   Updated: 2021/10/06 19:03:57 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **env)
{
	int	fin;
	int	fout;

	if (ac < 5)
		write(STDERR, "TOO FEW ARGUMENTS\n", 18);
	else if (ac > 5)
		write(STDERR, "TOO MANY ARGUMENTS\n", 19);
	else
	{
		fin = ft_open(av[1], 'i');
		fout = ft_open(av[4], 'o');
		if (fin < 0  || fout < 0)
			return (-1);
		dup2(fin, STDIN); //redirecting infile as the input to the pipe
		dup2(fout, STDOUT); //redirecting the outfile as the output of the pipe
		pipex(fin, av, env);
	}
	return (1);
}

int	ft_open(char *file, char c)
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
		return(open(file, O_CREAT | O_WRONLY | O_TRUNC,
					S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH));
	}
	return (-1);
}

void	pipex(int fin, char **av, char **env)
{
	pid_t	child;
	int		cmd_pipe[2]; //creating an array to feed it to the funtion pipe

	pipe(cmd_pipe); //calling the function pipe, that will create a pipe, this assign a fd to cmd_pipe[1] and to cmd_pipe[2]
	child = fork(); //creating child
	if (child == 0) //we are in the child process
 	{
		close(cmd_pipe[0]); //we wont be using so we close it;
		dup2(cmd_pipe[1], STDOUT); //redirecting
		if (fin == STDIN)
			exit(1);
		exec(av[2], env);
	}
	else if (child > 0)
	{
		waitpid(child, NULL, 0);
		close(cmd_pipe[1]);
		dup2(cmd_pipe[0], STDIN);
		exec(av[3], env);
	}
	else
	{
		write(STDERR, "ERROR\n", 6);
	}
}

void	exec(char *cmd, char **env)
{
	char	*path; //path to the command
	char	**args; //the args the command needs, we split the cmd str in parts

	args = ft_strsplit(cmd, ' ');
	if (!args[0])
		exit(1);
	path = ft_path(args[0], env);
	execve(path, args, env);
}

char	*ft_path(char *cmd, char **env)
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
		if (access (bin, F_OK) == 0)
			return (bin);
		free(bin);
		path += ft_strsrch(path, ':') + 1;
	}
	return (cmd);
}
