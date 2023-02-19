/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_checkquote_bonus.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: psadeghi <psadeghi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/01 13:26:42 by psadeghi      #+#    #+#                 */
/*   Updated: 2023/02/01 13:26:44 by psadeghi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	ft_checkquote(char *s)
{
	int	i;

	i = ft_strlen(s) - 1;
	if (s[i] == '\'' || s[i] == '\"')
		return (0);
	return (-1);
}
