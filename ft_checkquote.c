/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_checkquote.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: psadeghi <psadeghi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/26 11:34:01 by psadeghi      #+#    #+#                 */
/*   Updated: 2023/02/01 13:26:28 by psadeghi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_checkquote(char *s)
{
	int	i;

	i = ft_strlen(s) - 1;
	if (s[i] == '\'' || s[i] == '\"')
		return (0);
	return (-1);
}
