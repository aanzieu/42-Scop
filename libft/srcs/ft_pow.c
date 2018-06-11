/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 09:57:08 by aanzieu           #+#    #+#             */
/*   Updated: 2018/05/14 13:04:28 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double	ft_pow(double nb, int power)
{
	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	else
	{
		if (power > 1)
			nb = nb * ft_pow(nb, (power - 1));
		return (nb);
	}
}
