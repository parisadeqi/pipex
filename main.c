/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: psadeghi <psadeghi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/26 13:46:58 by psadeghi      #+#    #+#                 */
/*   Updated: 2023/02/01 15:47:52 by psadeghi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_pipex	p;

	ft_argument(argc);
	if (pipe(p.ends) == -1)
		ft_errorprocess(1);
	p.pid1 = fork();
	ft_firstfork(envp, argv, p);
	p.pid2 = fork();
	ft_secondfork(envp, argv, p);
	ft_close(p);
	waitpid(p.pid1, NULL, 0);
	waitpid(p.pid2, &p.pid_status, 0);
	if (WIFEXITED(p.pid_status))
		p.pid_status = WEXITSTATUS(p.pid_status);
	return (p.pid_status);
}
