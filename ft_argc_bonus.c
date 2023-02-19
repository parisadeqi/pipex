/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_argc_bonus.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: psadeghi <psadeghi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/31 10:31:10 by psadeghi      #+#    #+#                 */
/*   Updated: 2023/02/10 17:53:22 by psadeghi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_argc_bonus(int argc, char **argv)
{
	if (argc < 5)
	{
		write(2, "pipex: ", 7);
		write(2, "the amount of arguments is not correct", 38);
		write(2, "\n", 1);
		exit(127);
	}
	if (ft_strcmp(argv[1], "here_doc") == 0 && (argc > 6 || argc < 5))
	{
		write(2, "pipex: ", 7);
		write(2, "the amount of arguments is not correct", 38);
		write(2, "\n", 1);
		exit(127);
	}
}
