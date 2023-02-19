/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_errorunsetpath_bonus.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: psadeghi <psadeghi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/10 17:24:55 by psadeghi      #+#    #+#                 */
/*   Updated: 2023/02/10 17:25:06 by psadeghi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_errorunsetpath(char *command)
{
	write(2, "pipex: ", 7);
	write(2, command, ft_strlen(command));
	write(2, ": No such file or directory", 27);
	write(2, "\n", 1);
	exit(127);
}
