/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_errorallocate.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: psadeghi <psadeghi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/02 16:36:01 by psadeghi      #+#    #+#                 */
/*   Updated: 2023/02/14 11:43:30 by psadeghi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_errorallacate(int i)
{
	if (i == 1)
	{
		write(2, "pipex: ", 7);
		write(2, "Cannot allocate memory.\n", 24);
		exit(errno);
	}
}

void	ft_free_access(char **address, char *path, char *str)
{
	ft_freeall(address);
	free(path);
	free(str);
	ft_errorallacate(1);
}
