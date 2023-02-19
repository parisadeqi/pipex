/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: psadeghi <psadeghi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/25 14:05:43 by psadeghi      #+#    #+#                 */
/*   Updated: 2023/02/01 13:25:36 by psadeghi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strchr(const char *s, int c)
{
	char	*ptr;
	char	n;

	ptr = (char *)s;
	n = (char) c;
	while (*ptr != n && *ptr != '\0')
		ptr++;
	if (n == *ptr)
		return (ptr);
	return (0);
}
