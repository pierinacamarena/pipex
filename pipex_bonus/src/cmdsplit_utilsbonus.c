/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmdsplit_utilsbonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 15:14:52 by pcamaren          #+#    #+#             */
/*   Updated: 2021/09/07 15:14:53 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	single_quota(char *str, char **cmd, t_splitter *split)
{
	split->i++;
	cmd[split->j] = ft_calloc(sizeof(char), ft_len(str, 39, split->i) + 1);
	if (!cmd)
		return ;
	while (str[split->i] != '\0' && str[split->i] != 39)
		cmd[split->j][split->count++] = str[split->i++];
}

void	double_quota(char *str, char **cmd, t_splitter *split)
{
	split->i++;
	cmd[split->j] = ft_calloc(sizeof(char), ft_len(str, 34, split->i) + 1);
	if (!cmd)
		return ;
	while (str[split->i] != '\0' && str[split->i] != 34)
		cmd[split->j][split->count++] = str[split->i++];
}

void	space_case(char *str, char **cmd, t_splitter *split)
{
	cmd[split->j] = ft_calloc(sizeof(char), ft_len(str, ' ', split->i) + 1);
	if (!cmd)
		return ;
	while (str[split->i] != '\0' && str[split->i] != ' ')
		cmd[split->j][split->count++] = str[split->i++];
}
