/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_errorcommand.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: psadeghi <psadeghi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/26 14:17:38 by psadeghi      #+#    #+#                 */
/*   Updated: 2023/02/10 18:35:30 by psadeghi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_errorcommand(char *command)
{
	write(2, "pipex: ", 7);
	write(2, command, ft_strlen(command));
	write(2, ": command not found", 19);
	write(2, "\n", 1);
	exit(127);
}
