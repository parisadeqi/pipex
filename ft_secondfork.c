/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_secondfork.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: psadeghi <psadeghi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/27 11:35:56 by psadeghi      #+#    #+#                 */
/*   Updated: 2023/02/10 17:28:04 by psadeghi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_secondfork(char **envp, char **argv, t_pipex p)
{
	char	*access_result;

	if (p.pid2 == -1)
		ft_errorprocess(1);
	if (p.pid2 == 0)
	{
		p.file[1] = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
		if (p.file[1] == -1)
			ft_errorfile(argv[4], 1);
		close(p.ends[1]);
		if (dup2(p.ends[0], 0) == -1)
			ft_errofunction(1);
		if (dup2(p.file[1], STDOUT_FILENO) == -1)
			ft_errofunction(1);
		close(p.ends[0]);
		p.command2 = ft_split(argv[3], ' ');
		if (!p.command2)
			ft_errorallacate(1);
		access_result = ft_access(p.command2[0], ft_path(envp));
		execve(access_result, p.command2, envp);
		ft_freeall(p.command2);
		ft_errorcommand(argv[3]);
	}
}
