/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_close.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: psadeghi <psadeghi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/27 12:00:38 by psadeghi      #+#    #+#                 */
/*   Updated: 2023/01/31 11:21:44 by psadeghi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_close(t_pipex p)
{
	close(p.ends[0]);
	close(p.ends[1]);
	close(p.file[0]);
	close(p.file[1]);
}
