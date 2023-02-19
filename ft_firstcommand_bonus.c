/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_firstcommand_bonus.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: psadeghi <psadeghi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/31 10:46:36 by psadeghi      #+#    #+#                 */
/*   Updated: 2023/02/14 17:23:57 by psadeghi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_firstcommand_bonus(char **envp, char **argv, t_bonus b, int fork_id)
{
	char	*access_result;

	if (fork_id == -1)
		ft_errorprocess(1);
	if (fork_id == 0)
	{
		b.file[0] = open(argv[1], O_RDONLY);
		if (b.file[0] == -1)
			ft_errorfile(argv[1], 1);
		close(b.ends[0]);
		if (dup2(b.file[0], STDIN_FILENO) == -1)
			ft_errofunction(1);
		if (dup2(b.ends[1], 1) == -1)
			ft_errofunction(1);
		close(b.ends[1]);
		b.command_bonus = ft_split(argv[2], ' ');
		if (!b.command_bonus)
			ft_errorallacate(1);
		access_result = ft_access(b.command_bonus[0], ft_path(envp));
		execve(access_result, b.command_bonus, envp);
		ft_freeall(b.command_bonus);
		ft_errorcommand(argv[2]);
	}
	wait(NULL);
}
