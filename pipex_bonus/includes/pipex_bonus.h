/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 19:28:50 by pcamaren          #+#    #+#             */
/*   Updated: 2021/10/07 15:46:16 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <stdio.h>

# define STDIN 0
# define STDOUT 1
# define STDERR 2

# define INFILE 0
# define OUTFILE 1

typedef struct s_splitter {
	int		len;
	int		i;
	int		j;
	int		count;
}	t_splitter;

char	*path_join(char *path, char *bin);
int		str_ncmp(char *str1, char *str2, int n);
int		str_ichr(char *str, char c);
char	*str_ndup(char *str, unsigned int n);
char	**str_split(char *str, char sep);
int		openfile(char *filename);
int		openoutfile(char *filename);
int		main(int ac, char **av, char **env);
char	**ft_malloc_words(char const *s, char c);
void	ft_malloc_letters(char const *s, char c, char **str);
char	**ft_strsplit(char const *s, char c);
void	ft_bzero(void *str, size_t n);
void	*ft_memset(void *str, int character, size_t n);
size_t	ft_strlen(const char *str);
char	*ft_str3join(char const *s1, char const *s2, char const *s3);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_free(char **str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_path(char *arg, char **env);
char	*cmd_tester(char **path_split, char *arg);
void	pipex(char **av, char **env, int fdin);
void	pipex2(char **av, char **env, int fdin, int i);
void	multipipe(int ac, char **av, char **env, int fdin);
void	exec(char *cmd, char **env);
void	ft_putstr(const char *str);
char	**cmd_split(const char *str);
char	**cmd_malloc(char *str, char **cmd, t_splitter *split);
int		ft_len(char const *s, char c, int i);
void	word_count(const char *str, int *i, int *count);
int		ft_count(const char *str);
void	single_quota(char *str, char **cmd, t_splitter *split);
void	double_quota(char *str, char **cmd, t_splitter *split);
void	space_case(char *str, char **cmd, t_splitter *split);
void	*ft_calloc(size_t count, size_t size);
void	error_manager(int pipex, pid_t child);
#endif
