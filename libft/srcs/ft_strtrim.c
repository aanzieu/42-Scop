/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 20:06:59 by aanzieu           #+#    #+#             */
/*   Updated: 2018/05/14 13:06:02 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

char		*ft_strtrim(char const *s)
{
	char	*new;
	size_t	start;
	size_t	len;
	size_t	i;

	start = 0;
	i = 0;
	if (!s)
		return (NULL);
	while (s[start] && ft_isspace(s[start]))
		start++;
	len = ft_strchr(s + start, '\0') - s;
	while (len > start && ft_isspace(s[len - 1]))
		len--;
	if (len < start)
		len = start;
	if ((new = (char*)malloc(sizeof(char) * (len - start + 1))) == NULL)
		return (NULL);
	while (i + start < len)
	{
		new[i] = s[start + i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
