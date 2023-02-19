/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_errorfunction_bonus.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: psadeghi <psadeghi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/09 13:42:26 by psadeghi      #+#    #+#                 */
/*   Updated: 2023/02/15 14:28:46 by psadeghi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_errofunction(int i)
{
	if (i == 1)
	{
		write(2, "pipex: ", 7);
		write(2, "dup2 function failed.\n", 22);
		exit(errno);
	}
}
