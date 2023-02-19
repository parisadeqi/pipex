/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_errorprocess_bonus.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: psadeghi <psadeghi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/01 13:30:38 by psadeghi      #+#    #+#                 */
/*   Updated: 2023/02/01 13:30:54 by psadeghi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_errorprocess(int i)
{
	if (i == 1)
	{
		write(2, "pipex: ", 7);
		write(2, "process failed.\n", 16);
		exit(errno);
	}
}
