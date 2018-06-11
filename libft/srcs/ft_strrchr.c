/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 20:06:34 by aanzieu           #+#    #+#             */
/*   Updated: 2018/05/14 13:05:56 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*temp;

	temp = ft_strchr(str, '\0');
	while (temp >= str)
	{
		if (*temp == (unsigned char)c)
			return ((char*)temp);
		temp--;
	}
	return (NULL);
}
