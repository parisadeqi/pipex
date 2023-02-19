/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_freeall_bonus.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: psadeghi <psadeghi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/02 15:58:30 by psadeghi      #+#    #+#                 */
/*   Updated: 2023/02/02 17:28:00 by psadeghi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*ft_freeall(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}
