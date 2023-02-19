/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_errorcommand_bonus.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: psadeghi <psadeghi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/01 13:28:15 by psadeghi      #+#    #+#                 */
/*   Updated: 2023/02/14 11:51:05 by psadeghi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_errorcommand(char *command)
{
	write(2, "pipex: ", 7);
	write(2, command, ft_strlen(command));
	write(2, ": command not found", 19);
	write(2, "\n", 1);
	exit(127);
}
