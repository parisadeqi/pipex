/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_excm_bonus.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: psadeghi <psadeghi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/09 13:06:02 by psadeghi      #+#    #+#                 */
/*   Updated: 2023/02/15 13:35:42 by psadeghi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_excm_bonus(char **envp, char *command, t_bonus b)
{
	b.command_bonus = ft_split(command, ' ');
	if (!b.command_bonus)
		ft_errorallacate(1);
	b.access_result = ft_access(b.command_bonus[0], ft_path(envp));
	execve(b.access_result, b.command_bonus, envp);
	ft_freeall(b.command_bonus);
	ft_errorcommand(command);
}

void	ft_excm_1bonus(char **envp, char *command, t_bonus *b)
{
	b->command_bonus = ft_split(command, ' ');
	if (!b->command_bonus)
		ft_errorallacate(1);
	b->access_result = ft_access(b->command_bonus[0], ft_path(envp));
	execve(b->access_result, b->command_bonus, envp);
	ft_freeall(b->command_bonus);
	ft_errorcommand(command);
}
