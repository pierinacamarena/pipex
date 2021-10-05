/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 17:36:47 by pcamaren          #+#    #+#             */
/*   Updated: 2021/10/05 19:41:40 by pcamaren         ###   ########.fr       */
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
		pipex(fin, fout, av, env);
	}
	return (1);
}

int	ft_open(char *file, char c)
{
	int	d;


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
}

void	pipex(int fin, int fout, char **av, char **env)
{
	int	end[2];
	int	status;
	pid_t	child1;
	pid_t	child2;

	pipe(end);
	child1 = fork();
	if (child1 < 0)
		write(STDERR, "error\n", 5);
	if (child1 == 0)
		child_one(av[2], env, fin, end);
	if (child2 < 0)
		write(STDERR, "error\n", 5);
	if (child2 == 0)
		child_two(av[3], env, fout, end);
	close(end[0]);
	close(end[1]);
	waitpid(child1, &status, 0);
	waitpid(child2, &status, 0);
}

void	child_one(char *cmd, char **env, int fin, int *end)
{
	close(end[0]);
	dup2(end[1], STDOUT);
	close(end[1]);
	dup2(fin, STDIN);
	close(fin);
	exec(cmd, env);

}

void	child_two(char *cmd, char **env, int fout, int *end)
{
	close(end[1]);
	dup2(end[0], STDIN);
	close(end[0]);
	dup2(fout, STDOUT);
	exec(cmd, env);
}

void	exec(char *cmd, char **env)
{
	char	*path;
	char	**cmd_args;

	cmd_args = cmd_split(cmd, ' ');
}
