/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_heredoc_bonus.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: psadeghi <psadeghi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/06 17:13:16 by psadeghi      #+#    #+#                 */
/*   Updated: 2023/02/19 11:45:45 by parisasadeq   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	ft_second_bonus(char **argv, char **envp, t_bonus b)
{
	b.fork_id[0] = fork();
	ft_first_heredoc(argv, envp, b, b.fork_id[0]);
	b.fork_id[1] = fork();
	ft_second_heredoc(envp, argv, b, b.fork_id[1]);
	ft_close_bonus(&b, 0, argv);
	waitpid(b.fork_id[0], NULL, 0);
	waitpid(b.fork_id[1], &b.pid_status, 0);
	if (WIFEXITED(b.pid_status))
		b.pid_status = WEXITSTATUS(b.pid_status);
	return (b.pid_status);
}

void	ft_firstchild_heredoc(char **argv, t_bonus b)
{
	b.file[0] = open("here_doc", O_CREAT | O_RDWR | O_EXCL, 0777);
	if (b.file[0] == -1)
		ft_errorfile(argv[1], 1);
	b.limiter_newline = ft_strjoin(argv[2], "\n");
	if (!b.limiter_newline)
		ft_errorallacate(1);
	while (1)
	{
		b.line = get_next_line(0);
		if (!b.line)
			ft_errorallacate(1);
		if (ft_strcmp(b.limiter_newline, b.line) != 0)
		{
			write(b.file[0], b.line, ft_strlen(b.line));
			free(b.line);
		}
		if (ft_strcmp(b.limiter_newline, b.line) == 0)
			break ;
	}
	close(b.file[0]);
}

void	ft_first_heredoc(char **argv, char **envp, t_bonus b, int fork_id)
{
	if (fork_id == -1)
		ft_errorprocess(1);
	if (fork_id == 0)
	{
		ft_firstchild_heredoc(argv, b);
		b.file[0] = open("here_doc", O_RDONLY);
		if (b.file[0] == -1)
			ft_errorfile(argv[1], 1);
		close(b.ends[0]);
		if (dup2(b.file[0], STDIN_FILENO) == -1)
			ft_errofunction(1);
		if (dup2(b.ends[1], 1) == -1)
			ft_errofunction(1);
		close(b.ends[1]);
		close(b.file[0]);
		unlink("here_doc");
		ft_excm_bonus(envp, argv[3], b);
	}
	wait(NULL);
}

void	ft_second_heredoc(char **envp, char **argv, t_bonus b, int fork_id)
{
	if (fork_id == -1)
		ft_errorprocess(1);
	if (fork_id == 0)
	{
		b.file[1] = open(argv[5], O_CREAT | O_WRONLY | O_APPEND, 0644);
		if (b.file[1] == -1)
			ft_errorfile(argv[5], 1);
		close(b.ends[1]);
		if (dup2(b.ends[0], 0) == -1)
			ft_errofunction(1);
		if (dup2(b.file[1], STDOUT_FILENO) == -1)
			ft_errofunction(1);
		close(b.ends[0]);
		close(b.file[1]);
		ft_excm_bonus(envp, argv[4], b);
	}
}
