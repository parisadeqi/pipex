/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main_bonus.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: psadeghi <psadeghi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/27 15:27:03 by psadeghi      #+#    #+#                 */
/*   Updated: 2023/02/14 17:27:06 by psadeghi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"
#include <stdio.h>

int	main(int argc, char *argv[], char *envp[])
{
	t_bonus	b;

	ft_argc_bonus(argc, argv);
	if (pipe(b.ends) == -1)
		ft_errorprocess(1);
	b.forkindex = -1;
	if (ft_strcmp(argv[1], "here_doc") == 0)
		b.pid_status = ft_second_bonus(argv, envp, b);
	else
		b.pid_status = ft_first_bonus(argc, argv, envp, b);
	return (b.pid_status);
}
