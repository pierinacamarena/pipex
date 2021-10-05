/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 19:26:31 by pcamaren          #+#    #+#             */
/*   Updated: 2021/10/05 19:41:33 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

#define STDIN 0
#define STDOUT 1
#define STDERR 2

int	ft_open(char *file, char c);
void	pipex(int f1, int f2, char **ag, char **env);
void	child_one(char *cmd, char **env, int fin, int *end);
void	child_two(char *cmd, char **env, int fout, int *end);
void	exec(char *cmd, char **env);
char	**cmd_split(char *cmd, char c);
char	*cmd_dup(char *cmd, int n);
#endif
