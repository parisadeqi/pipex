/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: psadeghi <psadeghi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/11 15:13:04 by psadeghi      #+#    #+#                 */
/*   Updated: 2023/02/01 13:19:28 by psadeghi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strnstr(const char	*haystack, const char	*needle, size_t	len)
{
	size_t	n;
	size_t	h;

	h = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	while (haystack[h] != '\0' && h < len)
	{
		n = 0;
		while (needle[n] == haystack[h + n] && h + n < len)
		{
			if (needle[n + 1] == '\0')
				return ((char *)haystack + h);
			n++;
		}
		h++;
	}
	return (0);
}
