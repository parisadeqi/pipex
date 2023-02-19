/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lastcommand_bonus.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: psadeghi <psadeghi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/31 11:04:08 by psadeghi      #+#    #+#                 */
/*   Updated: 2023/02/15 16:27:03 by psadeghi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_lastcommand_bonus(int argc, char **envp, char **argv, t_bonus *b)
{
	char	*access_result;

	b->fork_id[argc - 4] = fork();
	if (b->fork_id[argc - 4] == -1)
		ft_errorprocess(1);
	if (b->fork_id[argc - 4] == 0)
	{
		b->file[1] = open(argv[argc - 1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
		if (b->file[1] == -1)
			ft_errorfile(argv[argc - 1], 1);
		close(b->ends[1]);
		if (dup2(b->ends[0], 0) == -1)
			ft_errofunction(1);
		if (dup2(b->file[1], STDOUT_FILENO) == -1)
			ft_errofunction(1);
		close(b->ends[0]);
		b->command_bonus = ft_split(argv[argc - 2], ' ');
		if (!b->command_bonus)
			ft_errorallacate(1);
		access_result = ft_access(b->command_bonus[0], ft_path(envp));
		execve(access_result, b->command_bonus, envp);
		ft_freeall(b->command_bonus);
		ft_errorcommand(argv[argc - 2]);
	}
}
