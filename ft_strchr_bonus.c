/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr_bonus.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: psadeghi <psadeghi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/01 13:25:56 by psadeghi      #+#    #+#                 */
/*   Updated: 2023/02/01 13:25:58 by psadeghi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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
