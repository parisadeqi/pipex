/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_errorfile_bonus.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: psadeghi <psadeghi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/01 13:29:20 by psadeghi      #+#    #+#                 */
/*   Updated: 2023/02/14 14:09:08 by psadeghi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_errorfile(char *file, int i)
{
	if (i == 1)
	{
		if (access(file, F_OK) != 0)
		{
			write(2, "pipex: ", 7);
			write(2, file, ft_strlen(file));
			write(2, ": No such file or directory", 27);
			write(2, "\n", 1);
			exit(errno);
		}
		if (access(file, X_OK) != 0 && (access(file, F_OK) == 0))
		{
			write(2, "pipex: ", 7);
			write(2, file, ft_strlen(file));
			write(2, ": Permission denied", 19);
			write(2, "\n", 1);
			exit(1);
		}
	}
}
