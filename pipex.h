/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 19:26:31 by pcamaren          #+#    #+#             */
/*   Updated: 2021/10/06 18:51:30 by pcamaren         ###   ########.fr       */
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


int		ft_open(char *file, char c);
void	pipex(int fd, char **ag, char **env);
void	child_one(char *cmd, char **env, int fin, int *end);
void	child_two(char *cmd, char **env, int fout, int *end);
void	exec(char *cmd, char **env);
void	ft_putstr(char const *s);
char	*cmd_dup(char *cmd, unsigned int n);
char	*ft_path(char *cmd, char **env);
int		ft_strsrch(char *str, char c);
int		ft_strncmp(char *str, char *str2, int n);
char	*joinpath(char *path, char *bin);
char	**ft_strsplit(char const *s, char c);
void	ft_malloc_letters(char const *s, char c, char **str);
char	**ft_malloc_words(char const *s, char c);
void	ft_bzero(void *str, size_t n);
void	*ft_memset(void *str, int character, size_t n);

#endif
