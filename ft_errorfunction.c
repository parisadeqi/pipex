/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_errorfunction.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: psadeghi <psadeghi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/09 13:39:12 by psadeghi      #+#    #+#                 */
/*   Updated: 2023/02/09 13:43:10 by psadeghi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_errofunction(int i)
{
	if (i == 1)
	{
		write(2, "pipex: ", 7);
		write(2, "dup2 function failed.\n", 22);
		exit(errno);
	}
}
