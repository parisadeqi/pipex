/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_firstfork.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: psadeghi <psadeghi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/27 11:36:00 by psadeghi      #+#    #+#                 */
/*   Updated: 2023/02/09 13:45:42 by psadeghi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_firstfork(char **envp, char **argv, t_pipex p)
{
	char	*access_result;

	if (p.pid1 == -1)
		ft_errorprocess(1);
	if (p.pid1 == 0)
	{
		p.file[0] = open(argv[1], O_RDONLY);
		if (p.file[0] == -1)
			ft_errorfile(argv[1], 1);
		close(p.ends[0]);
		if (dup2(p.file[0], STDIN_FILENO) == -1)
			ft_errofunction(1);
		if (dup2(p.ends[1], 1) == -1)
			ft_errofunction(1);
		close(p.ends[1]);
		p.command1 = ft_split(argv[2], ' ');
		if (!p.command1)
			ft_errorallacate(1);
		access_result = ft_access(p.command1[0], ft_path(envp));
		execve(access_result, p.command1, envp);
		ft_freeall(p.command1);
		ft_errorcommand(argv[2]);
	}
}
