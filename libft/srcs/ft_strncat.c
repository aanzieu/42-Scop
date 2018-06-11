/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 20:06:17 by aanzieu           #+#    #+#             */
/*   Updated: 2018/05/14 13:05:46 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = -1;
	j = ft_strlen(dest);
	k = ft_strlen(src);
	while (++i < k && i < n)
		dest[j + i] = src[i];
	dest[j + i] = '\0';
	return (dest);
}
