/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_first_bonus.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: psadeghi <psadeghi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/09 13:28:08 by psadeghi      #+#    #+#                 */
/*   Updated: 2023/02/15 16:27:58 by psadeghi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	ft_first_bonus(int argc, char **argv, char **envp, t_bonus b)
{
	b.commandnumber = 2;
	b.forkindex = 0;
	b.fork_id[0] = fork();
	ft_firstcommand_bonus(envp, argv, b, b.fork_id[0]);
	ft_middlecommands_bonus(argc, argv, envp, &b);
	ft_lastcommand_bonus(argc, envp, argv, &b);
	ft_close_bonus(&b, 0, argv);
	b.forkindex = -1;
	while (++b.forkindex <= argc - 4)
	{
		waitpid(b.fork_id[b.forkindex], &b.pid_status, 0);
		if (WIFEXITED(b.pid_status))
			b.pid_status = WEXITSTATUS(b.pid_status);
	}
	return (b.pid_status);
}

void	ft_middlecommands_bonus(int argc, char **argv, char **envp, t_bonus *b)
{
	while (++b->commandnumber < argc - 2 && ++b->forkindex <= argc - 5)
	{
		if (pipe(b->secondpipe) == -1)
			ft_errorprocess(1);
		b->fork_id[b->forkindex] = fork();
		if (b->fork_id[b->forkindex] == -1)
			ft_errorprocess(1);
		if (b->fork_id[b->forkindex] == 0)
		{
			ft_close_bonus(b, 1, argv);
			if (dup2(b->ends[0], 0) == -1)
				ft_errofunction(1);
			if (dup2(b->secondpipe[1], 1) == -1)
				ft_errofunction(1);
			ft_close_bonus(b, 2, argv);
			ft_excm_1bonus(envp, argv[b->commandnumber], b);
		}
		ft_close_bonus(b, 2, argv);
		close(b->ends[1]);
		if (pipe(b->ends) == -1)
			ft_errorprocess(1);
		if (dup2(b->secondpipe[0], b->ends[0]) == -1)
			ft_errofunction(1);
		close(b->secondpipe[0]);
	}
}
