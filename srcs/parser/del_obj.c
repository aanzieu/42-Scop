/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_obj.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 10:41:17 by aanzieu           #+#    #+#             */
/*   Updated: 2018/12/10 14:21:39 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/scop.h"

static void		obj_rel_surf(struct s_obj_surf *sp)
{
	if (sp->pibo)
		glDeleteBuffers(1, &sp->pibo);
	sp->pibo = 0;
	if (sp->poly_vertx)
		free(sp->poly_vertx);
}

void			obj_del_surf(t_obj *obj, int si)
{
	obj_rel_surf(obj->sv + si);
	memmove(obj->sv + si,
			obj->sv + si + 1,
			(obj->surface_count - si - 1) * sizeof(struct s_obj_surf));
	obj->surface_count--;
}

void			obj_mini(t_obj *obj)
{
	int si;

	si = obj->surface_count - 1;
	while (si >= 0)
	{
		if (obj->sv[si].poly_count == 0)
			obj_del_surf(obj, si);
		--si;
	}
}
