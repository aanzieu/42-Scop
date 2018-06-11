/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 20:04:48 by aanzieu           #+#    #+#             */
/*   Updated: 2018/05/14 13:04:21 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *src, int c, size_t n)
{
	size_t	j;

	j = 0;
	while (j < n)
	{
		if ((unsigned char)c == ((unsigned char*)src)[j])
			return ((unsigned char*)src + j);
		j++;
	}
	return (NULL);
}
