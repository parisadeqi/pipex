/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_close_bonus.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: psadeghi <psadeghi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/31 11:21:24 by psadeghi      #+#    #+#                 */
/*   Updated: 2023/02/14 17:14:49 by psadeghi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_close_bonus(t_bonus *b, int i, char **argv)
{
	if (i == 0)
	{
		close(b->ends[0]);
		close(b->ends[1]);
		close(b->file[0]);
		close(b->file[1]);
		if (ft_strcmp(argv[1], "here_doc") != 0)
		{
			close(b->secondpipe[0]);
			close(b->secondpipe[1]);
		}
	}
	if (i == 1)
	{
		close(b->ends[1]);
		close(b->secondpipe[0]);
	}
	if (i == 2)
	{
		close(b->ends[0]);
		close(b->secondpipe[1]);
	}
}
