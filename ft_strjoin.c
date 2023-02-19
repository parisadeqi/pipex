/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: psadeghi <psadeghi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/13 11:06:30 by psadeghi      #+#    #+#                 */
/*   Updated: 2023/02/01 13:24:43 by psadeghi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ns;
	int		i;
	int		j;

	ns = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!ns || !s1 || !s2)
		return (0);
	i = 0;
	while (s1[i] != '\0')
	{
		ns[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
		ns[i++] = s2[j++];
	ns[i] = '\0';
	return (ns);
}
