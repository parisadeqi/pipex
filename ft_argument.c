/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_argument.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: psadeghi <psadeghi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/26 14:58:56 by psadeghi      #+#    #+#                 */
/*   Updated: 2023/02/10 17:52:21 by psadeghi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_argument(int argc)
{
	if (argc != 5)
	{
		write(2, "pipex: ", 7);
		write(2, "the amount of arguments is not correct", 38);
		write(2, "\n", 1);
		exit(127);
	}
}
