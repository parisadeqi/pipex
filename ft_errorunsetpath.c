/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_errorunsetpath.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: psadeghi <psadeghi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/10 17:16:41 by psadeghi      #+#    #+#                 */
/*   Updated: 2023/02/10 17:21:48 by psadeghi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_errorunsetpath(char *command)
{
	write(2, "pipex: ", 7);
	write(2, command, ft_strlen(command));
	write(2, ": No such file or directory", 27);
	write(2, "\n", 1);
	exit(127);
}
