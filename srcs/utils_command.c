/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 16:50:50 by aanzieu           #+#    #+#             */
/*   Updated: 2018/12/18 17:55:21 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	display_command(void)
{
	dprintf(1, "------------- COMMAND -----------\n");
	dprintf(1, "Active / Desactive Rotation  :  [R]\n");
	dprintf(1, "Active / Desactive Texture   :  [T]\n");
	dprintf(1, "Active / Desactive Wireframe :  [ESCAPE]\n");
	dprintf(1, "Active / Desactive Mouse Mov :  [X] \n");
	dprintf(1, "--------------\n");
	dprintf(1, "Move Key : [Q] [W] [E] [A] [S] [D]\n");
	dprintf(1, "--------------\n");
	dprintf(1, "Moose : Zoom Molette\n");
	dprintf(1, "Quit program                 :  [ECHAP]\n");
	dprintf(1, "--------------\n");
}

int		display_usage(void)
{
	dprintf(1, "Usage: ./bin/scop [obj]\n");
	dprintf(1, "Choose: 1 42\n");
	dprintf(1, "      : 2 Tea1\n");
	dprintf(1, "      : 3 Tea2\n");
	dprintf(1, "--------------\n");
	dprintf(1, "Or : ./bin/scop [obj] [bmp]\n");
	return (0);
}
