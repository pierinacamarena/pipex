/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multipipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 16:44:33 by pcamaren          #+#    #+#             */
/*   Updated: 2021/10/08 16:54:42 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	pipex2(char **av, char **env, int fdin, int i)
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
		exec(av[i], env);
		close(end[1]);
	}
	else
	{
		waitpid(child, NULL, 0);
		close(end[1]);
		dup2(end[0], STDIN);
	}
}
