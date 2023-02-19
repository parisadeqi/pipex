/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc_bonus.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: psadeghi <psadeghi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/01 13:27:27 by psadeghi      #+#    #+#                 */
/*   Updated: 2023/02/01 13:27:29 by psadeghi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_bzero(void	*s, size_t	n)
{
	char	*start_s;

	start_s = (char *) s;
	while (n > 0)
	{
		*start_s = 0;
		start_s++;
		n--;
	}
}

void	*ft_calloc(size_t	count, size_t	size)
{
	void	*dst;

	dst = malloc (count * size);
	if (dst == 0)
		return (0);
	ft_bzero(dst, count * size);
	return (dst);
}
