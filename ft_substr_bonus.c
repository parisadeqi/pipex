/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr_bonus.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: psadeghi <psadeghi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/01 13:23:32 by psadeghi      #+#    #+#                 */
/*   Updated: 2023/02/01 13:23:34 by psadeghi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*ft_substr(char	*s, unsigned int start, size_t	len)
{
	char	*ns;
	size_t	i;
	size_t	j;

	if (!s)
		return (0);
	if ((size_t)start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen (s) - start;
	ns = (char *)malloc(sizeof(char) * (len + 1));
	if (ns == 0)
		return (0);
	i = start;
	j = 0;
	while (i < ft_strlen(s) && j < len)
		ns[j++] = s[i++];
	ns[j] = '\0';
	return (ns);
}
