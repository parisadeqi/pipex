/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_access_bonus.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: psadeghi <psadeghi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/01 13:24:14 by psadeghi      #+#    #+#                 */
/*   Updated: 2023/02/19 11:46:15 by parisasadeq   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*ft_path(char **envp)
{
	int		i;
	char	*str;

	i = 0;
	while (envp[i] != 0)
	{
		if (ft_strnstr(envp[i], "PATH=", 6) != 0)
		{
			str = ft_substr(ft_strnstr(envp[i], "PATH=", 6), 5, \
			ft_strlen(ft_strnstr(envp[i], "PATH=", 6)) - 5);
			if (!str)
				ft_errorallacate(1);
			return (str);
		}
		i++;
	}
	return (NULL);
}

char	*ft_access(char *command, char *path)
{
	int		j;
	char	**address;
	char	*command_path;
	char	*str;

	j = 0;
	str = NULL;
	if (access(command, X_OK) == 0)
		return (free(path), command);
	if (!path)
		ft_errorunsetpath(command);
	address = ft_split(path, ':');
	if (!address || !command)
		return (ft_freeall(address), free(path), NULL);
	while (address[j] != 0)
	{
		str = ft_strjoin(address[j], "/");
		command_path = ft_strjoin(str, command);
		if (!command_path || !str)
			ft_free_access(address, path, str);
		if (access(command_path, X_OK) == 0)
			return (command_path);
		j++;
	}
	return (ft_freeall(address), free(path), free(str), command);
}
