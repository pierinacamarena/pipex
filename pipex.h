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

char	*path_join (char *path, char *bin);
int		str_ncmp (char *str1, char *str2, int n);
int		str_ichr (char *str, char c);
char	*str_ndup (char *str, unsigned int n);
char	**str_split (char *str, char sep);
int		openfile (char *filename, int mode);
char	**ft_malloc_words(char const *s, char c);
void	ft_malloc_letters(char const *s, char c, char **str);
char	**ft_strsplit(char const *s, char c);
void	ft_bzero(void *str, size_t n);
void	*ft_memset(void *str, int character, size_t n);
size_t  ft_strlen(const char *str);
char	*ft_str3join(char const *s1, char const *s2, char const *s3);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_free(char **str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);


#endif
