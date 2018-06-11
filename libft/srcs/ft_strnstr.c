/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 20:06:31 by aanzieu           #+#    #+#             */
/*   Updated: 2018/05/14 13:05:54 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	int		count;
	int		start;
	int		end;

	if (needle[0] == '\0')
		return ((char*)haystack);
	count = 0;
	while (haystack[count] && n > 0)
	{
		if (n < ft_strlen(needle))
			return (NULL);
		start = 0;
		end = count;
		while (haystack[end] == needle[start] && haystack[end] && needle[start])
		{
			start++;
			end++;
		}
		if (needle[start] == '\0')
			return ((char*)haystack + count);
		n--;
		count++;
	}
	return (NULL);
}
