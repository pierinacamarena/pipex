/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamarena <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 20:07:16 by pcamaren          #+#    #+#             */
/*   Updated: 2021/09/02 20:07:18 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*copy;

	copy = (void *)malloc(size * count);
	if (!copy)
		return (NULL);
	ft_bzero(copy, size * count);
	return (copy);
}

int	null_checker_special(char **str)
{
	int	len;

	len = 0;
	while (str[len])
	{
		if (str[len] == NULL)
			return (1);
		len++;
	}
	if (str[len] == NULL)
		return (1);
	return (0);
}
